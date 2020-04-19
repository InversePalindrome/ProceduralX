/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Utility/ActionDirectionConversion.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/Action.hpp"
#include "ECS/Direction.hpp"


namespace ECS::Utility
{
    Direction actionToDirection(Action action)
    {
        switch (action)
        {
        case Action::MoveUp:
            return Direction::Up;
        case Action::MoveDown:
            return Direction::Down;
        case Action::MoveRight:
            return Direction::Right;
        case Action::MoveLeft:
            return Direction::Left;
        default:
            return Direction::Undefined;
        }
    }

    Action directionToAction(Direction direction)
    {
        switch (direction)
        {
        case Direction::Up:
            return Action::MoveUp;
        case Direction::Down:
            return Action::MoveDown;
        case Direction::Right:
            return Action::MoveRight;
        case Direction::Left:
            return Action::MoveLeft;
        default:
            return Action::Undefined;
        }
    }
}