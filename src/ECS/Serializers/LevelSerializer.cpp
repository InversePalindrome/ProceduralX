/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - LevelSerializer.cpp
https://inversepalindrome.com/
*/


#include "ECS/Serializers/LevelSerializer.hpp"
#include "ECS/Serializers/EntitySerializer.hpp"

#include <pugixml.hpp>


void ECS::Serializers::serializeLevel(const entt::registry& registry, const std::string& filename)
{
    pugi::xml_document doc;

    auto declaration = doc.append_child(pugi::node_declaration);
    declaration.append_attribute("version") = "1.0";
    declaration.append_attribute("encoding") = "UTF-8";

    auto levelNode = doc.append_child("Level");

    registry.each([&registry, &levelNode](auto entity) 
        {
            auto entityNode = levelNode.append_child("Entity");

            serializeEntity(entity, registry, entityNode);
        });

    doc.save_file(filename.c_str());
}