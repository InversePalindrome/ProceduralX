/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Utility/ActionDirectionConversion.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "App/Action.hpp"
#include "ECS/Direction.hpp"


namespace ECS::Utility
{
    Direction actionToDirection(App::Action action);

    App::Action directionToAction(Direction direction);
}