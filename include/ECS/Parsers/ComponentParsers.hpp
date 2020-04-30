/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Parsers/ComponentParsers.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "App/ResourceManager.hpp"
#include "ECS/Components/BodyComponent.hpp"
#include "ECS/Components/JointComponent.hpp"
#include "ECS/Components/SpeedComponent.hpp"
#include "ECS/Components/StateComponent.hpp"
#include "ECS/Components/SoundComponent.hpp"
#include "ECS/Components/SpriteComponent.hpp"
#include "ECS/Components/ObjectComponent.hpp"
#include "ECS/Components/WeaponComponent.hpp"
#include "ECS/Components/DamageComponent.hpp"
#include "ECS/Components/HealthComponent.hpp"
#include "ECS/Components/AnimationComponent.hpp"
#include "ECS/Components/AccelerationComponent.hpp"
#include "ECS/Components/TransformComponent.hpp"
#include "ECS/Components/SatelliteComponent.hpp"
#include "ECS/Components/PathComponent.hpp"

#include <pugixml.hpp>


namespace ECS::Parsers
{
    void parseSprite(Components::SpriteComponent& sprite, const pugi::xml_node& spriteNode, App::ResourceManager& resourceManager);
    void parseAnimation(Components::AnimationComponent& animation, const pugi::xml_node& animationNode);
    void parseSound(Components::SoundComponent& sound, const pugi::xml_node& soundNode, App::ResourceManager& resourceManager);
    void parseTransform(Components::TransformComponent& transform, const pugi::xml_node& transformNode);
    void parseBody(Components::BodyComponent& body, const pugi::xml_node& bodyNode);
    void parseJoint(Components::JointComponent& joint, const pugi::xml_node& jointNode);
    void parseSpeed(Components::SpeedComponent& speed, const pugi::xml_node& speedNode);
    void parseAcceleration(Components::AccelerationComponent& acceleration, const pugi::xml_node& accelerationNode);
    void parseObject(Components::ObjectComponent& object, const pugi::xml_node& objectNode);
    void parseState(Components::StateComponent& state, const pugi::xml_node& stateNode);
    void parseWeapon(Components::WeaponComponent& weapon, const pugi::xml_node& weaponNode);
    void parseDamage(Components::DamageComponent& damage, const pugi::xml_node& damageNode);
    void parseHealth(Components::HealthComponent& health, const pugi::xml_node& healthNode);
    void parseSatellite(Components::SatelliteComponent& satellite, const pugi::xml_node& satelliteNode);
    void parsePath(Components::PathComponent& path, const pugi::xml_node& pathNode);
}