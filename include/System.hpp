/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - System.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <entt/entt.hpp>

#include <chrono>


class System
{
public:
    explicit System(entt::registry& registry);

    virtual ~System() = default;

    virtual void update(const std::chrono::nanoseconds& deltaTime) = 0;

protected:
    entt::registry& registry;
};