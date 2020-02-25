/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - LevelParser.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <entt/entt.hpp>

#include <pugixml.hpp>

#include <string>


namespace Parser
{
    void parseLevel(entt::registry& registry, entt::dispatcher& dispatcher, const std::string& filename);
}