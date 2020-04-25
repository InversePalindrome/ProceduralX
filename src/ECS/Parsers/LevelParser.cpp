/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Parsers/LevelParser.cpp
https://inversepalindrome.com/
*/


#include "ECS/Parsers/LevelParser.hpp"
#include "ECS/Parsers/EntityParser.hpp"


void ECS::Parsers::parseLevel(entt::registry& registry, App::ResourceManager& resourceManager,
    const std::string& filename)
{
    if (pugi::xml_document doc; doc.load_file(filename.c_str()))
    {
        if (auto levelNode = doc.child("Level"))
        {
            for (auto entityNode : levelNode.children("Entity"))
            {
                entt::entity entity;

                if (auto idAttribute = entityNode.attribute("id"))
                {
                    entity = registry.create(entt::entity{ idAttribute.as_int() });
                }
                else
                {
                    entity = registry.create();
                }
                
                if (auto filenameAttribute = entityNode.attribute("filename"))
                {
                    parseEntity(entity, registry, resourceManager, filenameAttribute.as_string());
                }
                else
                {
                    parseEntity(entity, registry, resourceManager, entityNode);
                }
            }
        }
    }
}