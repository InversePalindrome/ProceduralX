/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - PositionConversions.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "AppConstants.hpp"

#include <SFML/System/Vector2.hpp>


namespace Conversions
{
    inline sf::Vector2f graphicsToPhysicsPosition(const sf::Vector2f& position)
    {
        return { position.x / AppConstants::PIXELS_PER_METER, -position.y / AppConstants::PIXELS_PER_METER };
    }

    inline sf::Vector2f physicsToGraphicsPosition(const sf::Vector2f& position)
    {
        return { position.x * AppConstants::PIXELS_PER_METER, -position.y * AppConstants::PIXELS_PER_METER };
    }
}