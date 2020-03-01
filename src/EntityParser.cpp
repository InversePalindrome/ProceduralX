/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - EntityParser.cpp
https://inversepalindrome.com/
*/


#include "Events.hpp"
#include "EntityParser.hpp"
#include "ComponentTags.hpp"
#include "ComponentParsers.hpp"

#include <functional>
#include <unordered_map>


namespace
{
    std::unordered_map<std::string, std::function<void(entt::registry&, entt::dispatcher&, entt::entity, const pugi::xml_node&)>>
        componentParser =
            { {"Sprite", [](auto& registry, auto&, auto entity, const auto& node) { Parser::parseSprite(registry, entity, node); } },
            {"Animation", [](auto& registry, auto&, auto entity, const auto& node) { Parser::parseAnimation(registry, entity, node); } },
            {"Position", [](auto& registry, auto&, auto entity, const auto& node) { Parser::parsePosition(registry, entity, node); }},
            {"Rotation", [](auto& registry, auto&, auto entity, const auto& node) { Parser::parseRotation(registry, entity, node); }},
            {"Body", [](auto& registry, auto& dispatcher, auto entity, const auto& node) { Parser::parseBody(registry, dispatcher, entity, node); }},
            {"Speed", [](auto& registry, auto&, auto entity, const auto& node) { Parser::parseSpeed(registry, entity, node); }},
            {"Acceleration", [](auto& registry, auto&, auto entity, const auto& node) { Parser::parseAcceleration(registry, entity, node); }},
            {"Object", [](auto& registry, auto&, auto entity, const auto& node) { Parser::parseObject(registry, entity, node); }},
            {"Player", [](auto& registry, auto&, auto entity, const auto&) { registry.assign<Player>(entity); }}
    };
}

entt::entity Parser::parseEntity(entt::registry& registry, entt::dispatcher& dispatcher,
    const std::string& filename)
{
    auto entity = registry.create();

    if (pugi::xml_document doc; doc.load_file(filename.c_str()))
    {
        if (auto entityNode = doc.child("Entity"))
        {
            parseEntity(entity, registry, dispatcher, entityNode);
        }
    }

    return entity;
}

void Parser::parseEntity(entt::entity entity, entt::registry& registry, entt::dispatcher& dispatcher,
    const pugi::xml_node& entityNode)
{
    for (auto componentNode : entityNode.children())
    {
        componentParser.at(componentNode.name())(registry, dispatcher, entity, componentNode);
    }
}