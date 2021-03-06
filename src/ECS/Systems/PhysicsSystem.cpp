/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Systems/PhysicsSystem.cpp
https://inversepalindrome.com/
*/


#include "ECS/Systems/PhysicsSystem.hpp"
#include "ECS/Components/BodyComponent.hpp"
#include "ECS/Components/JointComponent.hpp"
#include "ECS/Components/TransformComponent.hpp"
#include "ECS/Components/PathComponent.hpp"
#include "ECS/Utility/IDConversions.hpp"
#include "ECS/Utility/AngleConversions.hpp"


ECS::Systems::PhysicsSystem::PhysicsSystem(entt::registry& registry, entt::dispatcher& dispatcher,
    EntityFactory& entityFactory) :
    System(registry, dispatcher, entityFactory),
    world({ 0.0f, 0.0f }),
    collisionManager(registry, dispatcher),
    destructionManager(registry)
{
    world.SetContactListener(&collisionManager);
    world.SetDestructionListener(&destructionManager);

    registry.on_construct<Components::BodyComponent>().connect<&PhysicsSystem::onBodyAdded>(this);
    registry.on_destroy<Components::BodyComponent>().connect<&PhysicsSystem::onBodyRemoved>(this);
    registry.on_construct<Components::JointComponent>().connect<&PhysicsSystem::onJointAdded>(this);
    registry.on_destroy<Components::JointComponent>().connect<&PhysicsSystem::onJointRemoved>(this);
    registry.on_construct<Components::PathComponent>().connect<&PhysicsSystem::onPathAdded>(this);
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
    auto& joint = registry.get<Components::JointComponent>(entity);

    auto entityIDA = joint.getEntityIDA();
    auto entityIDB = joint.getEntityIDB();

    auto entityA = Utility::getEntity(registry, entityIDA);
    auto entityB = Utility::getEntity(registry, entityIDB);

    if (registry.valid(entityA) && registry.valid(entityB) && registry.has<Components::BodyComponent>(entityA) &&
        registry.has<Components::BodyComponent>(entityB))
    {
        auto& bodyA = registry.get<Components::BodyComponent>(entityA);
        auto& bodyB = registry.get<Components::BodyComponent>(entityB);

        joint.initialize(world, bodyA.getBody(), bodyB.getBody());
    }
}

void ECS::Systems::PhysicsSystem::onJointRemoved(entt::registry&, entt::entity entity)
{
    auto& joint = registry.get<Components::JointComponent>(entity);

    jointsToRemove.push_back(joint.getJoint());
}

void ECS::Systems::PhysicsSystem::onPathAdded(entt::registry&, entt::entity entity)
{
    const auto& path = registry.get<Components::PathComponent>(entity);

    b2BodyDef pathBodyDef;

    auto* body = world.CreateBody(&pathBodyDef);
    body->SetUserData(reinterpret_cast<void*>(entity));

    for (const auto& point : path.getPathPoints())
    {
        b2CircleShape circle;
        circle.m_p = point;
        circle.m_radius = 1.f;

        b2FixtureDef pointFixtureDef;
        pointFixtureDef.isSensor = true;
        pointFixtureDef.shape = &circle;

        body->CreateFixture(&pointFixtureDef);
    }
}

void ECS::Systems::PhysicsSystem::updateEntityRemoval()
{
    for (auto* body : bodiesToRemove)
    {
        world.DestroyBody(body);
    }

    bodiesToRemove.clear();

    for (auto* joint : jointsToRemove)
    {
        world.DestroyJoint(joint);
    }

    jointsToRemove.clear();
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