/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - Constants.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "App/Seconds.hpp"

#include <string>


using namespace std::chrono_literals;

namespace App
{
    const std::string APP_NAME = "ProceduralX";
    const unsigned int WINDOW_WIDTH = 2048U;
    const unsigned int WINDOW_HEIGHT = 1536U;
    const Seconds TIME_PER_FRAME = 16ms;
    const int FRAMES_PER_SECOND = static_cast<int>(1 / TIME_PER_FRAME.count());
    const float PIXELS_PER_METER = 16.f;
}