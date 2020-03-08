/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ComponentParsers.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <entt/entt.hpp>

#include <pugixml.hpp>


namespace ECS::Parsers
{
    void parseSprite(entt::registry& registry, entt::entity entity, const pugi::xml_node& spriteNode);
    void parseAnimation(entt::registry& registry, entt::entity entity, const pugi::xml_node& animationNode);
    void parseSound(entt::registry& registry, entt::entity entity, const pugi::xml_node& soundNode);
    void parsePosition(entt::registry& registry, entt::entity entity, const pugi::xml_node& positionNode);
    void parseRotation(entt::registry& registry, entt::entity entity, const pugi::xml_node& positionNode);
    void parseBody(entt::registry& registry, entt::entity entity, const pugi::xml_node& bodyNode);
    void parseSpeed(entt::registry& registry, entt::entity entity, const pugi::xml_node& speedNode);
    void parseAcceleration(entt::registry& registry, entt::entity entity, const pugi::xml_node& accelerationNode);
    void parseObject(entt::registry& registry, entt::entity entity, const pugi::xml_node& objectNode);
    void parseState(entt::registry& registry, entt::entity entity, const pugi::xml_node& stateNode);
    void parseWeapon(entt::registry& registry, entt::entity entity, const pugi::xml_node& weaponNode);
}