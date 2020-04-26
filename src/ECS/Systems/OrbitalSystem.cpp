/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Systems/OrbitalSystem.cpp
https://inversepalindrome.com/
*/


#include "ECS/Systems/OrbitalSystem.hpp"


ECS::Systems::OrbitalSystem::OrbitalSystem(entt::registry& registry, entt::dispatcher& dispatcher, EntityFactory& entityFactory) :
    System(registry, dispatcher, entityFactory)
{
}

void ECS::Systems::OrbitalSystem::update(const App::Seconds& deltaTime)
{

}