/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - PositionConversions.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "App/Constants.hpp"

#include <SFML/System/Vector2.hpp>


namespace ECS::Utility
{
    inline sf::Vector2f graphicsToPhysicsPosition(const sf::Vector2f& position)
    {
        return { position.x / App::PIXELS_PER_METER, -position.y / App::PIXELS_PER_METER };
    }

    inline sf::Vector2f physicsToGraphicsPosition(const sf::Vector2f& position)
    {
        return { position.x * App::PIXELS_PER_METER, -position.y * App::PIXELS_PER_METER };
    }
}