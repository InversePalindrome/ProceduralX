/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Systems/PlayerSystem.cpp
https://inversepalindrome.com/
*/


#include "ECS/Action.hpp"
#include "ECS/Systems/PlayerSystem.hpp"
#include "ECS/Components/BodyComponent.hpp"
#include "ECS/Components/SpeedComponent.hpp"
#include "ECS/Components/AccelerationComponent.hpp"
#include "ECS/SteeringBehaviors.hpp"
#include "ECS/Utility/PositionConversions.hpp"
#include "ECS/Utility/ActionDirectionConversion.hpp"


ECS::Systems::PlayerSystem::PlayerSystem(entt::registry& registry, entt::dispatcher& dispatcher,
    EntityFactory& entityFactory) :
    System(registry, dispatcher, entityFactory),
    playerEntity(entt::null)
{
    registry.on_construct<entt::tag<"Player"_hs>>().connect<&PlayerSystem::onPlayerAdded>(this);
    dispatcher.sink<ActionTriggered>().connect<&PlayerSystem::movePlayer>(this);
    dispatcher.sink<MouseMoved>().connect<&PlayerSystem::rotatePlayer>(this);
    dispatcher.sink<MousePressed>().connect<&PlayerSystem::shootProjectile>(this);
}

void ECS::Systems::PlayerSystem::update(const App::Seconds& deltaTime)
{
}

void ECS::Systems::PlayerSystem::onPlayerAdded(entt::entity entity)
{
    playerEntity = entity;
}

void ECS::Systems::PlayerSystem::movePlayer(const ActionTriggered& event)
{
    auto& body = registry.get<Components::BodyComponent>(playerEntity);
    const auto& speed = registry.get<Components::SpeedComponent>(playerEntity);
    const auto& acceleration = registry.get<Components::AccelerationComponent>(playerEntity);

    body.applyLinearImpulse(SteeringBehaviors::move(body.getPosition(), Utility::actionToDirection(event.actionType), 
        body.getLinearVelocity(),acceleration.getLinearAcceleration(), speed.getLinearSpeed(), body.getMass()));
}

void ECS::Systems::PlayerSystem::rotatePlayer(const MouseMoved& event)
{
    auto worldPosition = Utility::graphicsToPhysicsPosition(event.mousePosition);

    auto& body = registry.get<Components::BodyComponent>(playerEntity);

    body.applyAngularImpulse(SteeringBehaviors::face(body.getPosition(), { worldPosition.x, worldPosition.y },
        body.getAngle(), body.getAngularVelocity(), body.getInertia()));
}

void ECS::Systems::PlayerSystem::shootProjectile(const MousePressed& event)
{
    dispatcher.trigger(ShootProjectile{ playerEntity });
}