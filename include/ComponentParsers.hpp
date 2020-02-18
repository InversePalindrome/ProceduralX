/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ComponentParsers.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <entt/entt.hpp>

#include <pugixml.hpp>


namespace Parser
{
    void parseSprite(entt::registry& registry, entt::entity entity, const pugi::xml_node& spriteNode);
}