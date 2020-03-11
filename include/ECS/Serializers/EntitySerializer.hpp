/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - EntitySerializer.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <entt/entt.hpp>

#include <pugixml.hpp>


namespace ECS::Serializers
{
    void serializeEntity(entt::entity entity, const std::string& filename);
    void serializeEntity(entt::entity entity, pugi::xml_node& entityNode);
}