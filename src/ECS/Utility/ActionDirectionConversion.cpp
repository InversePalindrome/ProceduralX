/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Utility/ActionDirectionConversion.cpp
https://inversepalindrome.com/
*/


#include "ECS/Utility/ActionDirectionConversion.hpp"


ECS::Direction ECS::Utility::actionToDirection(App::Action action)
{
    switch (action)
    {
    case App::Action::MoveUp:
        return Direction::Up;
    case App::Action::MoveDown:
        return Direction::Down;
    case App::Action::MoveRight:
        return Direction::Right;
    case App::Action::MoveLeft:
        return Direction::Left;
    default:
        return Direction::Undefined;
    }
}

App::Action ECS::Utility::directionToAction(Direction direction)
{
    switch (direction)
    {
    case Direction::Up:
        return App::Action::MoveUp;
    case Direction::Down:
        return App::Action::MoveDown;
    case Direction::Right:
        return App::Action::MoveRight;
    case Direction::Left:
        return App::Action::MoveLeft;
    default:
        return App::Action::Undefined;
    }
}