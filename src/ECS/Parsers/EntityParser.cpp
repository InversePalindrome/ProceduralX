/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - EntityParser.cpp
https://inversepalindrome.com/
*/


#include "ECS/Systems/Events.hpp"
#include "ECS/Parsers/EntityParser.hpp"
#include "ECS/Components/ComponentTags.hpp"
#include "ECS/Parsers/ComponentParsers.hpp"

#include <functional>
#include <unordered_map>


namespace
{
    std::unordered_map<std::string, std::function<void(entt::registry&, entt::entity, const pugi::xml_node&)>>
        componentParser =
    { 
            {"Sprite", [](auto& registry, auto entity, const auto& node) { ECS::Parsers::parseSprite(registry, entity, node); } },
            {"Animation", [](auto& registry, auto entity, const auto& node) { ECS::Parsers::parseAnimation(registry, entity, node); } },
            {"Sound", [](auto& registry, auto entity, const auto& node) { ECS::Parsers::parseSound(registry, entity, node); } },
            {"Position", [](auto& registry, auto entity, const auto& node) { ECS::Parsers::parsePosition(registry, entity, node); }},
            {"Rotation", [](auto& registry, auto entity, const auto& node) { ECS::Parsers::parseRotation(registry, entity, node); }},
            {"Body", [](auto& registry, auto entity, const auto& node) { ECS::Parsers::parseBody(registry, entity, node); }},
            {"Speed", [](auto& registry, auto entity, const auto& node) { ECS::Parsers::parseSpeed(registry, entity, node); }},
            {"Acceleration", [](auto& registry, auto entity, const auto& node) { ECS::Parsers::parseAcceleration(registry, entity, node); }},
            {"Object", [](auto& registry, auto entity, const auto& node) { ECS::Parsers::parseObject(registry, entity, node); }},
            {"State", [](auto& registry, auto entity, const auto& node) { ECS::Parsers::parseState(registry, entity, node); }},
            {"Weapon", [](auto& registry, auto entity, const auto& node) { ECS::Parsers::parseWeapon(registry, entity, node); }},
            {"Damage", [](auto& registry, auto entity, const auto& node) { ECS::Parsers::parseDamage(registry, entity, node); }},
            {"Player", [](auto& registry, auto entity, const auto&) { registry.assign<ECS::Components::Player>(entity); }
    }
    };
}

entt::entity ECS::Parsers::parseEntity(entt::registry& registry, const std::string& filename)
{
    auto entity = registry.create();

    if (pugi::xml_document doc; doc.load_file(filename.c_str()))
    {
        if (auto entityNode = doc.child("Entity"))
        {
            parseEntity(entity, registry, entityNode);
        }
    }

    return entity;
}

void ECS::Parsers::parseEntity(entt::entity entity, entt::registry& registry, const pugi::xml_node& entityNode)
{
    for (auto componentNode : entityNode.children())
    {
        componentParser.at(componentNode.name())(registry, entity, componentNode);
    }
}