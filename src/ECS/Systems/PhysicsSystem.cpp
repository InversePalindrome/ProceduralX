/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - PhysicsSystem.cpp
https://inversepalindrome.com/
*/


#include "App/Constants.hpp"
#include "ECS/Systems/PhysicsSystem.hpp"
#include "ECS/Components/BodyComponent.hpp"
#include "ECS/Components/SpeedComponent.hpp"
#include "ECS/Components/TransformComponent.hpp"
#include "ECS/Components/AccelerationComponent.hpp"
#include "ECS/Utility/AngleConversions.hpp"


ECS::Systems::PhysicsSystem::PhysicsSystem(entt::registry& registry, entt::dispatcher& dispatcher,
    EntityFactory& entityFactory) :
    System(registry, dispatcher, entityFactory),
    world({0.0f, 0.0f}),
    collisionManager(registry, dispatcher)
{
    world.SetContactListener(&collisionManager);

    dispatcher.sink<MoveEntity>().connect<&PhysicsSystem::onMoveEntity>(this);
    dispatcher.sink<RotateEntity>().connect<&PhysicsSystem::onRotateEntity>(this);
    registry.on_construct<Components::BodyComponent>().connect<&PhysicsSystem::onBodyAdded>(this);
    registry.on_destroy<Components::BodyComponent>().connect<&PhysicsSystem::onBodyRemoved>(this);
}

void ECS::Systems::PhysicsSystem::update(const App::Seconds& deltaTime)
{
    updateEntitiesTransforms();
    updateWorld(deltaTime);
}

void ECS::Systems::PhysicsSystem::onMoveEntity(const MoveEntity& event)
{
    auto entity = event.entity;

    auto& body = registry.get<Components::BodyComponent>(entity);
    const auto& speed = registry.get<Components::SpeedComponent>(entity);
    const auto& acceleration = registry.get<Components::AccelerationComponent>(entity);

    switch (event.direction)
    {
    case Direction::Up:
        body.applyLinearImpulse({ 0.f, body.getMass() * (b2Min(body.getLinearVelocity().y + 
            acceleration.getLinearAcceleration(), speed.getLinearSpeed()) - body.getLinearVelocity().y) });
        break;
    case Direction::Down:
        body.applyLinearImpulse({ 0.f, body.getMass() * (b2Max(body.getLinearVelocity().y -
            acceleration.getLinearAcceleration(), -speed.getLinearSpeed()) - body.getLinearVelocity().y) });
        break;
    case Direction::Right:
        body.applyLinearImpulse({ body.getMass() * (b2Min(body.getLinearVelocity().x + acceleration.getLinearAcceleration(),
            speed.getLinearSpeed()) - body.getLinearVelocity().x), 0.f });
        break;
    case Direction::Left:
        body.applyLinearImpulse({ body.getMass() * (b2Max(body.getLinearVelocity().x - acceleration.getLinearAcceleration(),
            -speed.getLinearSpeed()) - body.getLinearVelocity().x), 0.f });
        break;
    }
}

void ECS::Systems::PhysicsSystem::onRotateEntity(const RotateEntity& event)
{
    auto& body = registry.get<Components::BodyComponent>(event.entity);
    const auto& targetPosition = event.targetPosition;

    const auto desiredAngle = std::atan2f(targetPosition.y - body.getPosition().y, targetPosition.x - body.getPosition().x);
    const auto nextAngle = body.getAngle() + body.getAngularVelocity() / App::FRAMES_PER_SECOND;

    const auto totalRotation = std::remainderf(desiredAngle - nextAngle, 2 * boost::math::constants::pi<float>());
  
    body.applyAngularImpulse(body.getInertia() * totalRotation * App::FRAMES_PER_SECOND);
}

void ECS::Systems::PhysicsSystem::onBodyAdded(entt::entity entity)
{
    auto& body = registry.get<Components::BodyComponent>(entity);

    body.initialize(world);
    body.setUserData(reinterpret_cast<void*>(entity));
}

void ECS::Systems::PhysicsSystem::onBodyRemoved(entt::entity entity)
{
    auto& body = registry.get<Components::BodyComponent>(entity);

    world.DestroyBody(body.getBody());
}

void ECS::Systems::PhysicsSystem::updateEntitiesTransforms()
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