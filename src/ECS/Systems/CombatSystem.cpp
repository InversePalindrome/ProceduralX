/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - CombatSystem.cpp
https://inversepalindrome.com/
*/


#include "ECS/Systems/CombatSystem.hpp"
#include "ECS/Components/WeaponComponent.hpp"


ECS::Systems::CombatSystem::CombatSystem(entt::registry& registry, entt::dispatcher& dispatcher,
    EntityFactory& entityFactory) :
    System(registry, dispatcher, entityFactory)
{
    dispatcher.sink<ShootProjectile>().connect<&CombatSystem::onShootProjectile>(this);
}

void ECS::Systems::CombatSystem::update(const App::Seconds& deltaTime)
{

}

void ECS::Systems::CombatSystem::onShootProjectile(const ShootProjectile& event)
{
    auto shooterEntity = event.shooter;

    const auto& weapon = registry.get<Components::WeaponComponent>(shooterEntity);

    auto projectileEntity = entityFactory.createEntity(weapon.getProjectile());
}