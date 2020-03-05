/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - Events.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "Direction.hpp"
#include "EntityState.hpp"
#include "InputManager.hpp"

#include <SFML/System/Vector2.hpp>

#include <entt/entt.hpp>


struct MoveEntity
{
    entt::entity entity;
    Direction direction;
};

struct RotateEntity
{
    entt::entity entity;
    sf::Vector2f targetPosition;
};

struct ActionTriggered
{
    InputManager::Action actionType;
};

struct MouseMoved
{
    sf::Vector2f position;
};

struct MousePressed
{
    sf::Vector2f position;
};

struct StateChanged
{
    entt::entity entity;
    EntityState state;
};