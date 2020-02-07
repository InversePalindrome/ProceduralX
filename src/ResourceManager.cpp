/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ResourceManager.cpp
https://inversepalindrome.com/
*/


#include "ResourceManager.hpp"

#include <Thor/Resources/SfmlLoaders.hpp>


ResourceManager& ResourceManager::getInstance()
{
    static ResourceManager instance;

    return instance;
}

sf::Texture& ResourceManager::getTexture(TextureID textureID)
{
    return textures[textureID];
}

void ResourceManager::loadTexture(TextureID textureID, const std::string& filename)
{
    textures.acquire(textureID, thor::Resources::fromFile<sf::Texture>(filename));
}