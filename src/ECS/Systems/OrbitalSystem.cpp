/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Systems/OrbitalSystem.cpp
https://inversepalindrome.com/
*/


#include "App/Constants.hpp"
#include "ECS/SteeringBehaviors.hpp"
#include "ECS/Systems/OrbitalSystem.hpp"
#include "ECS/Components/IDComponent.hpp"
#include "ECS/Components/BodyComponent.hpp"
#include "ECS/Components/SpeedComponent.hpp"
#include "ECS/Components/SatelliteComponent.hpp"


ECS::Systems::OrbitalSystem::OrbitalSystem(entt::registry& registry, entt::dispatcher& dispatcher, EntityFactory& entityFactory) :
    System(registry, dispatcher, entityFactory)
{
    registry.on_construct<Components::IDComponent>().connect<&OrbitalSystem::onIDAdded>(this);
}

void ECS::Systems::OrbitalSystem::update(const App::Seconds& deltaTime)
{
    registry.view<Components::SatelliteComponent, Components::BodyComponent, Components::SpeedComponent>()
        .each([this](const auto& satellite, auto& body, const auto& speed)
            {
                auto primaryEntity = idToEntityMap[satellite.getPrimaryEntityID()];

                if (registry.valid(primaryEntity) && registry.has<Components::BodyComponent>(primaryEntity))
                {
                    int direction = 0;

                    if (satellite.getDirection() == RotationDirection::Clockwise)
                    {
                        direction = 1;
                    }
                    else
                    {
                        direction = -1;
                    }

                    const auto& primaryBody = registry.get<Components::BodyComponent>(primaryEntity);

                    body.applyLinearImpulse(SteeringBehaviors::orbit(body.getPosition(), primaryBody.getPosition(), body.getLinearVelocity(), direction * speed.getLinearSpeed()));
                    body.applyAngularImpulse(body.getInertia() * (direction * speed.getAngularSpeed() - body.getAngularVelocity()) / App::FRAMES_PER_SECOND);
                }
            });
}

void ECS::Systems::OrbitalSystem::onIDAdded(entt::registry&, entt::entity entity)
{
    const auto& id = registry.get<Components::IDComponent>(entity);

    idToEntityMap[id.getID()] = entity;
}