/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - PhysicsSystem.cpp
https://inversepalindrome.com/
*/


#include "PhysicsSystem.hpp"


PhysicsSystem::PhysicsSystem(entt::registry& registry) :
    System(registry),
    world({0.0f, 0.0f})
{
}

void PhysicsSystem::update(const std::chrono::nanoseconds& deltaTime)
{
    //world.Step()
}