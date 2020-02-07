/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ResourceManager.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ResourceID.hpp"

#include <Thor/Resources/ResourceHolder.hpp>

#include <SFML/Graphics/Texture.hpp>


class ResourceManager
{
public:
    static ResourceManager& getInstance();

    ResourceManager() = default;
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager(ResourceManager&&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;
    ResourceManager& operator=(ResourceManager&&) = delete;

    sf::Texture& getTexture(TextureID textureID);
    void loadTexture(TextureID textureID, const std::string& filename);

private:
    thor::ResourceHolder<sf::Texture, TextureID> textures;
};