/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SizeConversions.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "AppConstants.hpp"

#include <SFML/System/Vector2.hpp>


namespace Conversions
{
    inline sf::Vector2f pixelsToMetersSize(const sf::Vector2f& size)
    {
        return { size.x / AppConstants::PIXELS_PER_METER, size.y / AppConstants::PIXELS_PER_METER };
    }

    inline sf::Vector2f metersToPixelsSize(const sf::Vector2f& size)
    {
        return { size.x * AppConstants::PIXELS_PER_METER, size.y * AppConstants::PIXELS_PER_METER };
    }
}