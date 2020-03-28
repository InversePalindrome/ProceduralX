/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Utility/SizeConversions.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "App/Constants.hpp"

#include <SFML/System/Vector2.hpp>


namespace ECS::Utility
{
    inline sf::Vector2f pixelsToMetersSize(const sf::Vector2f& size)
    {
        return { size.x / App::PIXELS_PER_METER, size.y / App::PIXELS_PER_METER };
    }

    inline sf::Vector2f metersToPixelsSize(const sf::Vector2f& size)
    {
        return { size.x * App::PIXELS_PER_METER, size.y * App::PIXELS_PER_METER };
    }
}