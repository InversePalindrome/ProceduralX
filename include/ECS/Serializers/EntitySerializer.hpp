/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Serializers/EntitySerializer.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <entt/entt.hpp>

#include <pugixml.hpp>


namespace ECS::Serializers
{
    void serializeEntity(entt::entity entity, const entt::registry& registry, const std::string& filename);
    void serializeEntity(entt::entity entity, const entt::registry& registry, pugi::xml_node& entityNode);
}