/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - AnimationData.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "App/Seconds.hpp"

#include <SFML/Graphics/Rect.hpp>

#include <vector>


namespace ECS
{
    struct FrameData
    {
        App::Seconds relativeDuration;
        sf::IntRect frameRect;
    };

    struct AnimationData
    {
        std::vector<FrameData> frames;
        App::Seconds duration;
        bool loop;
    };
}