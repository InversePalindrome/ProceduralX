/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ComponentParsers.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "Components.hpp"

#include <entt/entt.hpp>

#include <pugixml.hpp>


namespace Parser
{
    ComponentVariant parseSprite(entt::registry& registry, entt::entity entity, const pugi::xml_node& spriteNode);
    ComponentVariant parsePosition(entt::registry& registry, entt::entity entity, const pugi::xml_node& positionNode);
    ComponentVariant parseRotation(entt::registry& registry, entt::entity entity, const pugi::xml_node& positionNode);
    ComponentVariant parseBody(entt::registry& registry, entt::dispatcher& dispatcher, entt::entity entity, const pugi::xml_node& bodyNode);
    ComponentVariant parseSpeed(entt::registry& registry, entt::entity entity, const pugi::xml_node& speedNode);
    ComponentVariant parseAcceleration(entt::registry& registry, entt::entity entity, const pugi::xml_node& accelerationNode);
}