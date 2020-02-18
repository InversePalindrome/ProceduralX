/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - EntityParser.cpp
https://inversepalindrome.com/
*/


#include "Events.hpp"
#include "EntityParser.hpp"
#include "ComponentParsers.hpp"

#include <pugixml.hpp>

#include <functional>
#include <unordered_map>


namespace
{
    std::unordered_map<std::string, std::function<void(entt::registry&, entt::entity, const pugi::xml_node&)>>
        componentParser =
    {
            {"Sprite", [](auto& registry, auto entity, const auto& node) { Parser::parseSprite(registry, entity, node); } }
    };

    void parseComponents(entt::registry& registry, entt::entity entity, const pugi::xml_node& entityNode)
    {
        for (auto componentNode : entityNode.children())
        {
            componentParser.at(componentNode.name())(registry, entity, componentNode);
        }
    }
}

entt::entity Parser::parseEntity(entt::registry& registry, entt::dispatcher& dispatcher,
    const std::string& filename)
{
    auto entity = registry.create();

    if (pugi::xml_document doc; doc.load_file(filename.c_str()))
    {
        if (auto entityNode = doc.child("Entity"))
        {
            ::parseComponents(registry, entity, entityNode);
        }
    }

    dispatcher.trigger(EntityParsed{ entity });

    return entity;
}