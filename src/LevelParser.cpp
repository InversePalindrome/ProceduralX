/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - LevelParser.cpp
https://inversepalindrome.com/
*/


#include "LevelParser.hpp"
#include "EntityParser.hpp"


void Parser::parseLevel(entt::registry& registry, entt::dispatcher& dispatcher, const std::string& filename)
{
    if (pugi::xml_document doc; doc.load_file(filename.c_str()))
    {
        if (auto levelNode = doc.child("Level"))
        {
            for (auto entityNode : levelNode.children("Entity"))
            {
                if (auto filenameAttribute = entityNode.attribute("filename"))
                {
                    Parser::parseEntity(registry, dispatcher, filenameAttribute.as_string());
                }
                else
                {
                    Parser::parseEntity(registry.create(), registry, dispatcher, entityNode);
                }
            }
        }
    }
}