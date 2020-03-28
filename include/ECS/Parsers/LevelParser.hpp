/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Parsers/LevelParser.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <entt/entt.hpp>

#include <pugixml.hpp>

#include <string>


namespace ECS::Parsers
{
    void parseLevel(entt::registry& registry, const std::string& filename);
}