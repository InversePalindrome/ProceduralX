/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - EntityParser.cpp
https://inversepalindrome.com/
*/


#include "ECS/Parsers/EntityParser.hpp"
#include "ECS/Components/ComponentTags.hpp"
#include "ECS/Parsers/ComponentParsers.hpp"

#include <functional>
#include <unordered_map>


namespace
{
    using namespace ECS::Parsers;
    using namespace ECS::Components;

    std::unordered_map<std::string, std::function<void(entt::registry&, entt::entity, const pugi::xml_node&)>>
        componentParser =
    { 
            {"Sprite", [](auto& registry, auto entity, const auto& node) 
            {
                registry.assign<ECS::Components::SpriteComponent>(entity, parseSprite(node)); 
            } },
            {"Animation", [](auto& registry, auto entity, const auto& node) 
            { 
                registry.assign<AnimationComponent>(entity, parseAnimation(node)); 
            } },
            {"Sound", [](auto& registry, auto entity, const auto& node) 
            { 
                registry.assign<SoundComponent>(entity, parseSound(node)); 
            } },
            {"Transform", [](auto& registry, auto entity, const auto& node) 
            { 
                registry.assign<TransformComponent>(entity, parseTransform(node)); 
            }},
            {"Body", [](auto& registry, auto entity, const auto& node) 
            { 
                registry.assign<BodyComponent>(entity, parseBody(node)); 
            }},
            {"Speed", [](auto& registry, auto entity, const auto& node) 
            { 
                registry.assign<SpeedComponent>(entity, parseSpeed(node));
            }},
            {"Acceleration", [](auto& registry, auto entity, const auto& node) 
            {
                registry.assign<AccelerationComponent>(entity, parseAcceleration(node));
            }},
            {"Object", [](auto& registry, auto entity, const auto& node) 
            { 
                registry.assign<ObjectComponent>(entity, parseObject(node)); 
            }},
            {"State", [](auto& registry, auto entity, const auto& node) 
            { 
                registry.assign<StateComponent>(entity, parseState(node)); 
            }},
            {"Weapon", [](auto& registry, auto entity, const auto& node) 
            { 
                registry.assign<WeaponComponent>(entity, parseWeapon(node));
            }},
            {"Damage", [](auto& registry, auto entity, const auto& node) 
            { 
                registry.assign<DamageComponent>(entity, parseDamage(node)); 
            }},
            {"Health", [](auto& registry, auto entity, const auto& node)
            {
                registry.assign<HealthComponent>(entity, parseHealth(node));
            }},
            {"Player", [](auto& registry, auto entity, const auto&)
            { 
                registry.assign<ECS::Components::Player>(entity);
            }
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