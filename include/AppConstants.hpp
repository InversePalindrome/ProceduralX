/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - AppConstants.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "Seconds.hpp"

#include <string>


using namespace std::chrono_literals;

namespace AppConstants
{
    const std::string APP_NAME = "ProceduralX";
    const unsigned int WINDOW_WIDTH = 2048U;
    const unsigned int WINDOW_HEIGHT = 1536U;
    const Seconds TIME_PER_FRAME = 16ms;
    const float PIXELS_PER_METER = 16.f;
}