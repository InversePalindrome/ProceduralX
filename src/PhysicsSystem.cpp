/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - PhysicsSystem.cpp
https://inversepalindrome.com/
*/


#include "AppConstants.hpp"
#include "PhysicsSystem.hpp"
#include "BodyComponent.hpp"
#include "PositionComponent.hpp"
#include "RotationComponent.hpp"


PhysicsSystem::PhysicsSystem(entt::registry& registry, entt::dispatcher& dispatcher) :
    System(registry, dispatcher),
    world({0.0f, 0.0f})
{
    dispatcher.sink<MoveEntity>().connect<&PhysicsSystem::onMoveEntity>(this);
}

void PhysicsSystem::update(const Seconds& deltaTime)
{
    registry.view<PositionComponent, RotationComponent, BodyComponent>().each([](auto& position, auto& rotation, const auto& body)
        {
            position.setPosition({ body.getPosition().x, body.getPosition().y });
            rotation.setAngle(body.getAngle());
        });

    const int VELOCITY_ITERATIONS = 6;
    const int POSITION_ITERATIONS = 2;

    world.Step(deltaTime.count(), VELOCITY_ITERATIONS, POSITION_ITERATIONS);
}

void PhysicsSystem::onMoveEntity(const MoveEntity& event)
{

}