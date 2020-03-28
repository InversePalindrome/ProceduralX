/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Systems/CombatSystem.cpp
https://inversepalindrome.com/
*/


#include "App/Constants.hpp"
#include "ECS/Utility/AngleConversions.hpp"
#include "ECS/Systems/CombatSystem.hpp"
#include "ECS/Components/BodyComponent.hpp"
#include "ECS/Components/SpeedComponent.hpp"
#include "ECS/Components/DamageComponent.hpp"
#include "ECS/Components/HealthComponent.hpp"
#include "ECS/Components/WeaponComponent.hpp"
#include "ECS/Components/TransformComponent.hpp"


ECS::Systems::CombatSystem::CombatSystem(entt::registry& registry, entt::dispatcher& dispatcher,
    EntityFactory& entityFactory) :
    System(registry, dispatcher, entityFactory)
{
    registry.on_construct<Components::WeaponComponent>().connect<&CombatSystem::onWeaponAdded>(this);
    registry.on_destroy<Components::WeaponComponent>().connect<&CombatSystem::onWeaponRemoved>(this);
    dispatcher.sink<CombatOccurred>().connect<&CombatSystem::onCombatOccurred>(this);
    dispatcher.sink<ShootProjectile>().connect<&CombatSystem::onShootProjectile>(this);
}

void ECS::Systems::CombatSystem::update(const App::Seconds& deltaTime)
{

}

void ECS::Systems::CombatSystem::onWeaponAdded(entt::entity entity)
{
    reloadStatusMap[entity] = true;
}

void ECS::Systems::CombatSystem::onWeaponRemoved(entt::entity entity)
{
    reloadStatusMap.erase(entity);
}

void ECS::Systems::CombatSystem::onCombatOccurred(const CombatOccurred& event)
{
    auto attackerEntity = event.attacker;
    auto victimEntity = event.victim;

    const auto& attackerDamage = registry.get<Components::DamageComponent>(attackerEntity);

    auto& victimHealth = registry.get<Components::HealthComponent>(victimEntity);

    victimHealth.setHealth(victimHealth.getHealth() - attackerDamage.getDamage());

    if (victimHealth.getHealth() <= 0)
    {
        registry.destroy(victimEntity);
    }
}

void ECS::Systems::CombatSystem::onShootProjectile(const ShootProjectile& event)
{
    auto shooterEntity = event.shooter;

    if (!reloadStatusMap[shooterEntity])
    {
        return;
    }

    reloadStatusMap[shooterEntity] = false;

    const auto& shooterWeapon = registry.get<Components::WeaponComponent>(shooterEntity);
    
    auto projectileEntity = entityFactory.createEntity(shooterWeapon.getProjectile());
    
    auto& projectileBody = registry.get<Components::BodyComponent>(projectileEntity);
    auto& projectileTransform = registry.get<Components::TransformComponent>(projectileEntity);
    const auto& projectileSpeed = registry.get<Components::SpeedComponent>(projectileEntity);

    const auto& shooterBody = registry.get<Components::BodyComponent>(shooterEntity);
    b2Vec2 shooterSize(shooterBody.getAABB().upperBound - shooterBody.getAABB().lowerBound);
    
    b2Vec2 projectileDirection(std::cos(shooterBody.getAngle()), std::sin(shooterBody.getAngle()));
    b2Vec2 projectileSize(projectileBody.getAABB().upperBound - projectileBody.getAABB().lowerBound);

    b2Vec2 velocityOffset(b2Abs(App::TIME_PER_FRAME.count() * shooterBody.getLinearVelocity()));
    b2Vec2 sizeOffset(0.5f * shooterSize + projectileSize);

    b2Vec2 projectilePositionOffset(projectileDirection.x * (sizeOffset.x + velocityOffset.x),
        projectileDirection.y * (sizeOffset.y + velocityOffset.y));
    
    projectileBody.setPosition(shooterBody.getPosition() + projectilePositionOffset);
    projectileBody.setAngle(shooterBody.getAngle());
    projectileBody.setLinearVelocity(shooterBody.getLinearVelocity());
    projectileBody.applyLinearImpulse(projectileBody.getMass() * projectileSpeed.getLinearSpeed()
        * projectileDirection);

    projectileTransform.setPosition({ projectileBody.getPosition().x, projectileBody.getPosition().y });
    projectileTransform.setAngle(Utility::radiansToDegrees(projectileBody.getAngle()));

    reloadTimer.add(shooterWeapon.getReloadTime(), [this, shooterEntity](auto) 
        {
            reloadStatusMap[shooterEntity] = true;
        });
        
    dispatcher.trigger(ChangeState{ shooterEntity, State::Shooting });
}