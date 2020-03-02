/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - EntityParser.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <entt/entt.hpp>

#include <pugixml.hpp>

#include <string>


namespace Parser
{
     entt::entity parseEntity(entt::registry& registry, const std::string& filename);

     void parseEntity(entt::entity entity, entt::registry& registry, const pugi::xml_node& entityNode);
}