/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - CombatSystem.cpp
https://inversepalindrome.com/
*/


#include "App/Constants.hpp"
#include "ECS/Systems/CombatSystem.hpp"
#include "ECS/Components/BodyComponent.hpp"
#include "ECS/Components/SpeedComponent.hpp"
#include "ECS/Components/DamageComponent.hpp"
#include "ECS/Components/HealthComponent.hpp"
#include "ECS/Components/WeaponComponent.hpp"


ECS::Systems::CombatSystem::CombatSystem(entt::registry& registry, entt::dispatcher& dispatcher,
    EntityFactory& entityFactory) :
    System(registry, dispatcher, entityFactory)
{
    dispatcher.sink<CombatOccurred>().connect<&CombatSystem::onCombatOccurred>(this);
    dispatcher.sink<ShootProjectile>().connect<&CombatSystem::onShootProjectile>(this);
}

void ECS::Systems::CombatSystem::update(const App::Seconds& deltaTime)
{

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
    const auto& shooterBody = registry.get<Components::BodyComponent>(shooterEntity);
    const auto& shooterWeapon = registry.get<Components::WeaponComponent>(shooterEntity);

    b2Vec2 shooterSize(shooterBody.getAABB().upperBound - shooterBody.getAABB().lowerBound);
    
    auto projectileEntity = entityFactory.createEntity(shooterWeapon.getProjectile());
    
    auto& projectileBody = registry.get<Components::BodyComponent>(projectileEntity);
    const auto& projectileSpeed = registry.get<Components::SpeedComponent>(projectileEntity);

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
      
    dispatcher.trigger(ChangeState{ shooterEntity, State::Shooting });
}