/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - App/ResourceID.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <cstddef>


namespace App
{
    enum class TextureID : std::size_t 
    {
        Null, SplashLogo, Spaceships, UFO, SpaceBackground, Planet1,
        Planet2, Planet3, Planet4, Meteor, RedProjectiles
    };

    enum class ImageID : std::size_t { Null };

    enum class FontID : std::size_t { Null };

    enum class SoundID : std::size_t { Null, Laser };
}