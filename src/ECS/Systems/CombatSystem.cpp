/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - CombatSystem.cpp
https://inversepalindrome.com/
*/


#include "ECS/Systems/CombatSystem.hpp"


ECS::Systems::CombatSystem::CombatSystem(entt::registry& registry, entt::dispatcher& dispatcher) :
    System(registry, dispatcher)
{
    dispatcher.sink<ShootProjectile>().connect<&CombatSystem::onShootProjectile>(this);
}

void ECS::Systems::CombatSystem::update(const App::Seconds& deltaTime)
{

}

void ECS::Systems::CombatSystem::onShootProjectile(const ShootProjectile& event)
{

}