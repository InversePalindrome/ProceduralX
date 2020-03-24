/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ComponentSerializers.hpp
https://inversepalindrome.com/
*/


#pragma once

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


namespace ECS::Serializers
{
    void serializeSprite(const Components::SpriteComponent& sprite, pugi::xml_node& spriteNode);
    void serializeAnimation(const Components::AnimationComponent& animation, pugi::xml_node& animationNode);
    void serializeSound(const Components::SoundComponent& sound, pugi::xml_node& soundNode);
    void serializeTransform(const Components::TransformComponent& transform, pugi::xml_node& transformNode);
    void serializeBody(const Components::BodyComponent& body, pugi::xml_node& bodyNode);
    void serializeSpeed(const Components::SpeedComponent& speed, pugi::xml_node& speedNode);
    void serializeAcceleration(const Components::AccelerationComponent& acceleration, pugi::xml_node& accelerationNode);
    void serializeObject(const Components::ObjectComponent& object, pugi::xml_node& objectNode);
    void serializeState(const Components::StateComponent& state, pugi::xml_node& stateNode);
    void serializeWeapon(const Components::WeaponComponent& weapon, pugi::xml_node& weaponNode);
    void serializeDamage(const Components::DamageComponent& damage, pugi::xml_node& damageNode);
    void serializeHealth(const Components::HealthComponent& health, pugi::xml_node& healthNode);
}