/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - PhysicsSystem.cpp
https://inversepalindrome.com/
*/


#include "AppConstants.hpp"
#include "PhysicsSystem.hpp"
#include "BodyComponent.hpp"
#include "SpeedComponent.hpp"
#include "AngleConversions.hpp"
#include "PositionComponent.hpp"
#include "RotationComponent.hpp"
#include "AccelerationComponent.hpp"


PhysicsSystem::PhysicsSystem(entt::registry& registry, entt::dispatcher& dispatcher) :
    System(registry, dispatcher),
    world({0.0f, 0.0f}),
    collisionManager(dispatcher)
{
    world.SetContactListener(&collisionManager);

    dispatcher.sink<MoveEntity>().connect<&PhysicsSystem::onMoveEntity>(this);
    dispatcher.sink<RotateEntity>().connect<&PhysicsSystem::onRotateEntity>(this);
    dispatcher.sink<CreateBody>().connect<&PhysicsSystem::onCreateBody>(this);
    dispatcher.sink<DestroyBody>().connect<&PhysicsSystem::onDestroyBody>(this);
}

void PhysicsSystem::update(const Seconds& deltaTime)
{
    registry.view<PositionComponent, RotationComponent, BodyComponent>().each([](auto& position, auto& rotation, const auto& body)
        {
            position.setPosition({ body.getPosition().x, body.getPosition().y });
            rotation.setAngle(-Conversions::radiansToDegrees(body.getAngle()));
        });

    const int VELOCITY_ITERATIONS = 6;
    const int POSITION_ITERATIONS = 2;

    world.Step(deltaTime.count(), VELOCITY_ITERATIONS, POSITION_ITERATIONS);
}

void PhysicsSystem::onMoveEntity(const MoveEntity& event)
{
    auto& body = registry.get<BodyComponent>(event.entity);
    const auto& speed = registry.get<SpeedComponent>(event.entity);
    const auto& acceleration = registry.get<AccelerationComponent>(event.entity);

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

void PhysicsSystem::onRotateEntity(const RotateEntity& event)
{
    auto& body = registry.get<BodyComponent>(event.entity);

    const auto desiredAngle = std::atan2f(event.targetPosition.y - body.getPosition().y, event.targetPosition.x - body.getPosition().x);
    const auto nextAngle = body.getAngle() + body.getAngularVelocity() / AppConstants::FRAMES_PER_SECOND;

    const auto totalRotation = std::remainderf(desiredAngle - nextAngle, 2 * boost::math::constants::pi<float>());
  
    body.applyAngularImpulse(body.getInertia() * totalRotation * AppConstants::FRAMES_PER_SECOND);
}

void PhysicsSystem::onCreateBody(const CreateBody& event)
{
    auto& bodyComponent = event.body.get();

    auto fixtureDefs = event.fixtureDefs;
    auto shapes = event.shapes;

    auto* body = world.CreateBody(&event.bodyDef);

    for (std::size_t i = 0u; i < fixtureDefs.size(); ++i)
    {
        std::visit([&fixtureDefs, i](auto& shape) 
            {
                fixtureDefs[i].shape = &shape;
            }, shapes[i]);

       body->CreateFixture(&fixtureDefs[i]);
    }

    userBodyData.insert(event.entity);
    
    bodyComponent.setBody(body);
    bodyComponent.setUserData(&userBodyData.find(event.entity));
}

void PhysicsSystem::onDestroyBody(const DestroyBody& event)
{
    auto& body = event.body.get();

    userBodyData.erase(event.entity);
    world.DestroyBody(body.getBody());
}