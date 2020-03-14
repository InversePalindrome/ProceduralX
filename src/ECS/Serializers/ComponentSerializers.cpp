/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ComponentSerializers.cpp
https://inversepalindrome.com/
*/


#include "ECS/Serializers/ComponentSerializers.hpp"


void ECS::Serializers::serializeSprite(const Components::SpriteComponent& sprite, pugi::xml_node& spriteNode)
{
    spriteNode.set_name("Sprite");
}

void ECS::Serializers::serializeAnimation(const Components::AnimationComponent& animation, pugi::xml_node& animationNode)
{
    animationNode.set_name("Animation");
}

void ECS::Serializers::serializeSound(const Components::SoundComponent& sound, pugi::xml_node& soundNode)
{
    soundNode.set_name("Sound");
}

void ECS::Serializers::serializePosition(const Components::PositionComponent& position, pugi::xml_node& positionNode)
{
    positionNode.set_name("Position");
}

void ECS::Serializers::serializeRotation(const Components::RotationComponent& rotation, pugi::xml_node& rotationNode)
{
    rotationNode.set_name("Rotation");
}

void ECS::Serializers::serializeBody(const Components::BodyComponent& body, pugi::xml_node& bodyNode)
{
    bodyNode.set_name("Body");
}

void ECS::Serializers::serializeSpeed(const Components::SpeedComponent& speed, pugi::xml_node& speedNode)
{
    speedNode.set_name("Speed");
}

void ECS::Serializers::serializeAcceleration(const Components::AccelerationComponent& acceleration, pugi::xml_node& accelerationNode)
{
    accelerationNode.set_name("Acceleration");
}

void ECS::Serializers::serializeObject(const Components::ObjectComponent& object, pugi::xml_node& objectNode)
{
    objectNode.set_name("Object");
}

void ECS::Serializers::serializeState(const Components::StateComponent& state, pugi::xml_node& stateNode)
{
    stateNode.set_name("State");
}

void ECS::Serializers::serializeWeapon(const Components::WeaponComponent& weapon, pugi::xml_node& weaponNode)
{
    weaponNode.set_name("Weapon");
}

void ECS::Serializers::serializeDamage(const Components::DamageComponent& damage, pugi::xml_node& damageNode)
{
    damageNode.set_name("Damage");
}

void ECS::Serializers::serializeHealth(const Components::HealthComponent& health, pugi::xml_node& healthNode)
{
    healthNode.set_name("Health");
}