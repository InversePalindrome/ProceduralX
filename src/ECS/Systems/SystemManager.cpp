/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Systems/SystemManager.cpp
https://inversepalindrome.com/
*/


#include "ECS/Systems/SystemManager.hpp"


ECS::Systems::SystemManager::SystemManager(entt::registry& registry, entt::dispatcher& dispatcher,
    ECS::EntityFactory& entityFactory) :
    registry(registry),
    dispatcher(dispatcher),
    entityFactory(entityFactory)
{
}
void ECS::Systems::SystemManager::update(const App::Seconds& deltaTime)
{
    for (auto&& system : systems)
    {
        system.second->update(deltaTime);
    }
}

void ECS::Systems::SystemManager::clearSystems()
{
    systems.clear();
}