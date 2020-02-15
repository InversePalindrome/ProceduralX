/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ResourceManager.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ResourceID.hpp"

#include <Thor/Resources/ResourceHolder.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Audio/SoundBuffer.hpp>


class ResourceManager
{
public:
    static ResourceManager& getInstance();

    ResourceManager(const ResourceManager&) = delete;
    ResourceManager(ResourceManager&&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;
    ResourceManager& operator=(ResourceManager&&) = delete;

    void loadResources(const std::string& filename);

    sf::Texture& getTexture(TextureID textureID);
    void loadTexture(TextureID textureID, const std::string& filename);

private:
    ResourceManager() = default;

    thor::ResourceHolder<sf::Texture, TextureID> textures;
    thor::ResourceHolder<sf::Image, ImageID> images;
    thor::ResourceHolder<sf::Font, FontID> fonts;
    thor::ResourceHolder<sf::SoundBuffer, SoundID> sounds;
};