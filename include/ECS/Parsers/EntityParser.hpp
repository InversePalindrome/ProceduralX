/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Parsers/EntityParser.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "App/ResourceManager.hpp"

#include <entt/entt.hpp>

#include <pugixml.hpp>

#include <string>


namespace ECS::Parsers
{
     void parseEntity(entt::entity, entt::registry& registry, App::ResourceManager& resourceManager,
         const std::string& filename);

     void parseEntity(entt::entity entity, entt::registry& registry, App::ResourceManager& resourceManager,
         const pugi::xml_node& entityNode);
}