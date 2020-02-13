/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - PhysicsSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "System.hpp"

#include <box2d/b2_world.h>


class PhysicsSystem : public System
{
public:
    explicit PhysicsSystem(entt::registry& registry);

    virtual void update(const std::chrono::nanoseconds& deltaTime) override;

private:
    b2World world;
};