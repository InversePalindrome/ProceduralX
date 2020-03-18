/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ObjectType.hpp
https://inversepalindrome.com/
*/


#pragma once


namespace ECS
{
    enum class ObjectType { Player = (1 << 0), Enemy = (1 << 1), Projectile = (1 << 2),
        Alive = Player | Enemy };
}