/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - App/AudioSettings.hpp
https://inversepalindrome.com/
*/


#pragma once


namespace App
{
    class AudioSettings
    {
    public:
        static AudioSettings& getInstance();

        AudioSettings(const AudioSettings&) = delete;
        AudioSettings& operator=(const AudioSettings&) = delete;
        AudioSettings(AudioSettings&&) = delete;
        AudioSettings& operator=(AudioSettings&&) = delete;

        float getSoundVolume() const;
        void setSoundVolume(float soundVolume);

        float getMusicVolume() const;
        void setMusicVolume(float musicVolume);

    private:
        float soundVolume;
        float musicVolume;

        AudioSettings();
    };
}