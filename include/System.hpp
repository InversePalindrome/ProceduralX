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
    System(const System&) = delete;
    System& operator=(const System&) = delete;
    System(System&&) = default;
    System& operator=(System&&) = default;

    virtual ~System() = default;

    virtual void update(const std::chrono::nanoseconds& deltaTime) = 0;

protected:
    entt::registry& registry;
};