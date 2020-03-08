/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - Events.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/Direction.hpp"
#include "ECS/State.hpp"
#include "App/InputManager.hpp"

#include <SFML/System/Vector2.hpp>

#include <entt/entt.hpp>


namespace ECS::Systems
{
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
        App::InputManager::Action actionType;
    };

    struct MouseMoved
    {
        sf::Vector2f position;
    };

    struct MousePressed
    {
        sf::Vector2f position;
    };

    struct ChangeState
    {
        entt::entity entity;
        State state;
    };

    struct StateChanged
    {
        entt::entity entity;
        State state;
    };

    struct ShootProjectile
    {
        entt::entity shooter;
        sf::Vector2f position;
    };
}