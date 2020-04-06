/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Parsers/ComponentParsers.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "App/ResourceManager.hpp"
#include "ECS/Components/BodyComponent.hpp"
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

#include <pugixml.hpp>


namespace ECS::Parsers
{
    Components::SpriteComponent parseSprite(const pugi::xml_node& spriteNode, App::ResourceManager& resourceManager);
    Components::AnimationComponent parseAnimation(const pugi::xml_node& animationNode);
    Components::SoundComponent parseSound(const pugi::xml_node& soundNode, App::ResourceManager& resourceManager);
    Components::TransformComponent parseTransform(const pugi::xml_node& transformNode);
    Components::BodyComponent parseBody(const pugi::xml_node& bodyNode);
    Components::SpeedComponent parseSpeed(const pugi::xml_node& speedNode);
    Components::AccelerationComponent parseAcceleration(const pugi::xml_node& accelerationNode);
    Components::ObjectComponent parseObject(const pugi::xml_node& objectNode);
    Components::StateComponent parseState(const pugi::xml_node& stateNode);
    Components::WeaponComponent parseWeapon(const pugi::xml_node& weaponNode);
    Components::DamageComponent parseDamage(const pugi::xml_node& damageNode);
    Components::HealthComponent parseHealth(const pugi::xml_node& healthNode);
}