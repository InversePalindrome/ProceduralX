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
        float getVolume() const;
        void setVolume(float volume);

        float getPitch() const;
        void setPitch(float pitch);

    private:
        float volume;
        float pitch;
    };
}