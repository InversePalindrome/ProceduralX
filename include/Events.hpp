/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - Events.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <entt/entt.hpp>


struct EntityParsed
{
    entt::entity entity;
};

template<typename T>
struct ComponentParsed
{
    T component;
    entt::entity entity;
};