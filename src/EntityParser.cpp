/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - EntityParser.cpp
https://inversepalindrome.com/
*/


#include "Events.hpp"
#include "Components.hpp"
#include "EntityParser.hpp"
#include "ComponentParsers.hpp"

#include <functional>
#include <unordered_map>


namespace
{
    std::unordered_map<std::string, std::function<ComponentVariant(entt::registry&, entt::dispatcher&, entt::entity, const pugi::xml_node&)>>
        componentParser =
    {
            {"Sprite", [](auto& registry, auto&, auto entity, const auto& node) { return Parser::parseSprite(registry, entity, node); } },
             {"Animation", [](auto& registry, auto&, auto entity, const auto& node) { return Parser::parseAnimation(registry, entity, node); } },
            {"Position", [](auto& registry, auto&, auto entity, const auto& node) { return Parser::parsePosition(registry, entity, node); }},
            {"Rotation", [](auto& registry, auto&, auto entity, const auto& node) { return Parser::parseRotation(registry, entity, node); }},
            {"Body", [](auto& registry, auto& dispatcher, auto entity, const auto& node) { return Parser::parseBody(registry, dispatcher, entity, node); }},
            {"Speed", [](auto& registry, auto&, auto entity, const auto& node) { return Parser::parseSpeed(registry, entity, node); }},
            {"Acceleration", [](auto& registry, auto&, auto entity, const auto& node) { return Parser::parseAcceleration(registry, entity, node); }},
            {"Object", [](auto& registry, auto&, auto entity, const auto& node) { return Parser::parseObject(registry, entity, node); }},
            {"Player", [](auto& registry, auto&, auto entity, const auto& node) 
            {
                auto player = registry.assign<Player>(entity);
                return std::ref(player); 
            }}
    };

    void parseComponents(entt::registry& registry, entt::dispatcher& dispatcher, entt::entity entity, const pugi::xml_node& entityNode)
    {
        for (auto componentNode : entityNode.children())
        {
            std::visit([&dispatcher, entity](auto component) 
                {
                   dispatcher.trigger(ComponentParsed<std::decay_t<decltype(component.get())>>{component, entity});
                }, componentParser.at(componentNode.name())(registry, dispatcher, entity, componentNode));
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
            parseEntity(entity, registry, dispatcher, entityNode);
        }
    }

    return entity;
}

void Parser::parseEntity(entt::entity entity, entt::registry& registry, entt::dispatcher& dispatcher,
    const pugi::xml_node& entityNode)
{
    ::parseComponents(registry, dispatcher, entity, entityNode);

    dispatcher.trigger(EntityParsed{ entity });
}