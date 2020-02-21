/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - Events.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "Direction.hpp"

#include <entt/entt.hpp>

#include <functional>


struct EntityParsed
{
    entt::entity entity;
};

template<typename T>
struct ComponentParsed
{
    std::reference_wrapper<T> component;
    entt::entity entity;
};

struct MoveEntity
{
    entt::entity entity;
    Direction direction;
};