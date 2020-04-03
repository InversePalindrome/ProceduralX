/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - App/AudioSettings.cpp
https://inversepalindrome.com/
*/


#include "App/AudioSettings.hpp"


App::AudioSettings& App::AudioSettings::getInstance()
{
    static AudioSettings instance;

    return instance;
}

float App::AudioSettings::getSoundVolume() const
{
    return soundVolume;
}

void App::AudioSettings::setSoundVolume(float soundVolume)
{
    this->soundVolume = soundVolume;
}

float App::AudioSettings::getMusicVolume() const
{
    return musicVolume;
}

void App::AudioSettings::setMusicVolume(float musicVolume)
{
    this->musicVolume = musicVolume;
}

App::AudioSettings::AudioSettings() :
    soundVolume(100.f),
    musicVolume(100.f)
{
}