/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - App/AudioSettings.cpp
https://inversepalindrome.com/
*/


#include "App/AudioSettings.hpp"


float App::AudioSettings::getVolume() const
{
    return volume;
}

void App::AudioSettings::setVolume(float volume)
{
    this->volume = volume;
}

float App::AudioSettings::getPitch() const
{
    return pitch;
}

void App::AudioSettings::setPitch(float pitch)
{
    this->pitch = pitch;
}