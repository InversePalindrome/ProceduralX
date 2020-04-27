/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Parsers/EntityParser.cpp
https://inversepalindrome.com/
*/


#include "ECS/Parsers/EntityParser.hpp"
#include "ECS/Parsers/ComponentParsers.hpp"

#include <functional>
#include <unordered_map>


namespace
{
    using namespace ECS::Parsers;
    using namespace ECS::Components;

    std::unordered_map<std::string, std::function<void(entt::registry&, App::ResourceManager&,
        entt::entity, const pugi::xml_node&)>>
        componentParser =
    { 
            {"Sprite", [](auto& registry, auto& resourceManager, auto entity, const auto& node) 
            {
                SpriteComponent sprite;
                parseSprite(sprite, node, resourceManager);

                registry.assign<SpriteComponent>(entity, sprite); 
            } },
            {"Animation", [](auto& registry, auto&, auto entity, const auto& node) 
            { 
                AnimationComponent animation;
                parseAnimation(animation, node);

                registry.assign<AnimationComponent>(entity, animation); 
            } },
            {"Sound", [](auto& registry, auto& resourceManager, auto entity, const auto& node) 
            { 
                SoundComponent sound;
                parseSound(sound, node,resourceManager);

                registry.assign<SoundComponent>(entity, sound); 
            } },
            {"Transform", [](auto& registry, auto&, auto entity, const auto& node) 
            { 
                TransformComponent transform;
                parseTransform(transform, node);

                registry.assign<TransformComponent>(entity, transform); 
            }},
            {"Body", [](auto& registry, auto&, auto entity, const auto& node) 
            { 
                BodyComponent body;
                parseBody(body, node);

                registry.assign<BodyComponent>(entity, body); 
            }},
            {"Joint", [](auto& registry, auto&, auto entity, const auto& node)
            {
                JointComponent joint;
                parseJoint(joint, node);

                registry.assign<JointComponent>(entity, joint);
            }},
            {"Speed", [](auto& registry, auto&, auto entity, const auto& node) 
            { 
                SpeedComponent speed;
                parseSpeed(speed, node);

                registry.assign<SpeedComponent>(entity, speed);
            }},
            {"Acceleration", [](auto& registry, auto&, auto entity, const auto& node) 
            {
                AccelerationComponent acceleration;
                parseAcceleration(acceleration, node);

                registry.assign<AccelerationComponent>(entity, acceleration);
            }},
            {"Object", [](auto& registry, auto&, auto entity, const auto& node) 
            { 
                ObjectComponent object;
                parseObject(object, node);

                registry.assign<ObjectComponent>(entity, object); 
            }},
            {"State", [](auto& registry, auto&, auto entity, const auto& node) 
            { 
                StateComponent state;
                parseState(state, node);

                registry.assign<StateComponent>(entity, state); 
            }},
            {"Weapon", [](auto& registry, auto&, auto entity, const auto& node) 
            { 
                WeaponComponent weapon;
                parseWeapon(weapon, node);

                registry.assign<WeaponComponent>(entity, weapon);
            }},
            {"Damage", [](auto& registry, auto&, auto entity, const auto& node) 
            { 
                DamageComponent damage;
                parseDamage(damage, node);

                registry.assign<DamageComponent>(entity, damage); 
            }},
            {"Health", [](auto& registry, auto&, auto entity, const auto& node)
            {
                HealthComponent health;
                parseHealth(health, node);

                registry.assign<HealthComponent>(entity, health);
            }},
            {"Satellite", [](auto& registry, auto&, auto entity, const auto& node)
            {
                SatelliteComponent satellite;
                parseSatellite(satellite, node);

                registry.assign<SatelliteComponent>(entity, satellite);
            }},
            {"Player", [](auto& registry, auto&, auto entity, const auto&)
            { 
                registry.assign<entt::tag<"Player"_hs>>(entity);
            }
    }
    };
}

void ECS::Parsers::parseEntity(entt::entity entity, entt::registry& registry, App::ResourceManager& resourceManager,
    const std::string& filename)
{
    if (pugi::xml_document doc; doc.load_file(filename.c_str()))
    {
        if (auto entityNode = doc.child("Entity"))
        {
            parseEntity(entity, registry, resourceManager, entityNode);
        }
    }
}

void ECS::Parsers::parseEntity(entt::entity entity, entt::registry& registry, 
    App::ResourceManager& resourceManager, const pugi::xml_node& entityNode)
{
    for (auto componentNode : entityNode.children())
    {
        componentParser.at(componentNode.name())(registry, resourceManager, entity, componentNode);
    }
}