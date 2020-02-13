/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - AppConstants.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <string>
#include <chrono>


using namespace std::chrono_literals;

namespace AppConstants
{
    const std::string APP_NAME = "ProceduralX";
    const unsigned int WINDOW_WIDTH = 2048U;
    const unsigned int WINDOW_HEIGHT = 1536U;
    const std::chrono::nanoseconds TIME_PER_FRAME = 16ms;
}