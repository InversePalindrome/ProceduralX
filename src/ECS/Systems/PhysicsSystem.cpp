/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Systems/PhysicsSystem.cpp
https://inversepalindrome.com/
*/


#include "ECS/Systems/PhysicsSystem.hpp"
#include "ECS/Components/BodyComponent.hpp"
#include "ECS/Components/JointComponent.hpp"
#include "ECS/Components/TransformComponent.hpp"
#include "ECS/Utility/AngleConversions.hpp"


ECS::Systems::PhysicsSystem::PhysicsSystem(entt::registry& registry, entt::dispatcher& dispatcher,
    EntityFactory& entityFactory) :
    System(registry, dispatcher, entityFactory),
    world({0.0f, 0.0f}),
    collisionManager(registry, dispatcher)
{
    world.SetContactListener(&collisionManager);

    registry.on_construct<Components::BodyComponent>().connect<&PhysicsSystem::onBodyAdded>(this);
    registry.on_destroy<Components::BodyComponent>().connect<&PhysicsSystem::onBodyRemoved>(this);
    registry.on_construct<Components::JointComponent>().connect<&PhysicsSystem::onJointAdded>(this);
    registry.on_destroy<Components::JointComponent>().connect<&PhysicsSystem::onJointRemoved>(this);
}

void ECS::Systems::PhysicsSystem::update(const App::Seconds& deltaTime)
{
    updateEntityRemoval();
    updateEntityTransforms();
    updateWorld(deltaTime);
}

void ECS::Systems::PhysicsSystem::onBodyAdded(entt::registry&, entt::entity entity)
{
    auto& body = registry.get<Components::BodyComponent>(entity);
    
    body.initialize(world);
    body.setUserData(reinterpret_cast<void*>(entity));
}

void ECS::Systems::PhysicsSystem::onBodyRemoved(entt::registry&, entt::entity entity)
{
    auto& body = registry.get<Components::BodyComponent>(entity);
    
    bodiesToRemove.push_back(body.getBody());
}

void ECS::Systems::PhysicsSystem::onJointAdded(entt::registry&, entt::entity entity)
{

}

void ECS::Systems::PhysicsSystem::onJointRemoved(entt::registry&, entt::entity entity)
{

}

void ECS::Systems::PhysicsSystem::updateEntityRemoval()
{
    for (auto* body : bodiesToRemove)
    {
        world.DestroyBody(body);
    }

    bodiesToRemove.clear();
}

void ECS::Systems::PhysicsSystem::updateEntityTransforms()
{
    registry.view<Components::BodyComponent, Components::TransformComponent>()
        .each([](const auto& body, auto& transform)
            {
                transform.setPosition({ body.getPosition().x, body.getPosition().y });
                transform.setAngle(Utility::radiansToDegrees(body.getAngle()));
            });
}

void ECS::Systems::PhysicsSystem::updateWorld(const App::Seconds& deltaTime)
{
    const int VELOCITY_ITERATIONS = 6;
    const int POSITION_ITERATIONS = 2;

    world.Step(deltaTime.count(), VELOCITY_ITERATIONS, POSITION_ITERATIONS);
}