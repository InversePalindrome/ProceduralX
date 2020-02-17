/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - System.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "Seconds.hpp"

#include <entt/entt.hpp>


class System
{
public:
    System(entt::registry& registry, entt::dispatcher& dispatcher);
    System(const System&) = delete;
    System& operator=(const System&) = delete;
    System(System&&) = default;
    System& operator=(System&&) = default;

    virtual ~System() = default;

    virtual void update(const Seconds& deltaTime) = 0;

protected:
    entt::registry& registry;
    entt::dispatcher& dispatcher;
};