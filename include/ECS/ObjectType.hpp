/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/ObjectType.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <flags/flags.hpp>


namespace ECS
{
    enum class ObjectType
    { 
        Player = (1 << 0), Enemy = (1 << 1), Projectile = (1 << 2),
        Planet = (1 << 3)
    };
}

ALLOW_FLAGS_FOR_ENUM(ECS::ObjectType)