/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Systems/PathSystem.cpp
https://inversepalindrome.com/
*/


#include "ECS/Systems/PathSystem.hpp"
#include "ECS/Components/PathComponent.hpp"
#include "ECS/Components/IDComponent.hpp"


ECS::Systems::PathSystem::PathSystem(entt::registry& registry, entt::dispatcher& dispatcher, EntityFactory& entityFactory) :
    System(registry, dispatcher, entityFactory)
{
    dispatcher.sink<CrossedPathPoint>().connect<&PathSystem::onCrossedPathPoint>(this);
}

void ECS::Systems::PathSystem::update(const App::Seconds& deltaTime)
{

}

void ECS::Systems::PathSystem::onCrossedPathPoint(const CrossedPathPoint& event)
{
    auto crossingEntity = event.crossingEntity;
    auto pathEntity = event.pathEntity;

    if (registry.has<Components::IDComponent>(pathEntity) && registry.has<Components::PathComponent>(pathEntity))
    {
        const auto& crossingEntityID = registry.get<Components::IDComponent>(crossingEntity);
        auto& path = registry.get<Components::PathComponent>(pathEntity);

        if (path.doesEntityUsePath(crossingEntityID.getID()))
        {
            path.moveToNextPointIndex(crossingEntityID.getID());
        }
    }
}