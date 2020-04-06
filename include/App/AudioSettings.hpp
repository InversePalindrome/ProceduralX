/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - App/AudioSettings.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <string>


namespace App
{
    class AudioSettings
    {
    public:
        AudioSettings();

        void loadAudioSettings(const std::string& filename);
        void saveAudioSettings(const std::string& filename);

        float getSoundVolume() const;
        void setSoundVolume(float soundVolume);

        float getMusicVolume() const;
        void setMusicVolume(float musicVolume);

    private:
        float soundVolume;
        float musicVolume;
    };
}