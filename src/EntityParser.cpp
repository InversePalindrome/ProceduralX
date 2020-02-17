/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - EntityParser.cpp
https://inversepalindrome.com/
*/


#include "Events.hpp"
#include "EntityParser.hpp"

#include <pugixml.hpp>

#include <functional>
#include <unordered_map>


namespace
{
    void parseComponents(entt::entity entity, const pugi::xml_node& entityNode)
    {
        for (auto componentNode : entityNode.children())
        {

        }
    }

    std::unordered_map<std::string, std::function<void(entt::entity, const pugi::xml_node&)>>
        componentParser = {};
}

entt::entity Parser::parseEntity(entt::registry& registry, entt::dispatcher& dispatcher,
    const std::string& filename)
{
    auto entity = registry.create();

    if (pugi::xml_document doc; doc.load_file(filename.c_str()))
    {
        if (auto entityNode = doc.child("Entity"))
        {
            ::parseComponents(entity, entityNode);
        }
    }

    dispatcher.trigger(EntityParsed{ entity });

    return entity;
}