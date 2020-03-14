/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - LevelSerializer.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <entt/entt.hpp>

#include <string>


namespace ECS::Serializers
{
    void serializeLevel(const entt::registry& registry, const std::string& filename);
}