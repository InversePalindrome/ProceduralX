/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - PhysicsSystem.cpp
https://inversepalindrome.com/
*/


#include "AppConstants.hpp"
#include "PhysicsSystem.hpp"


PhysicsSystem::PhysicsSystem(entt::registry& registry) :
    System(registry),
    world({0.0f, 0.0f})
{
}

void PhysicsSystem::update(const Seconds& deltaTime)
{
    const int VELOCITY_ITERATIONS = 6;
    const int POSITION_ITERATIONS = 2;

    world.Step(deltaTime.count(), VELOCITY_ITERATIONS, POSITION_ITERATIONS);
}