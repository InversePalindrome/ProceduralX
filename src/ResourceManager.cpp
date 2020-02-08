/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ResourceManager.cpp
https://inversepalindrome.com/
*/


#include "ResourceManager.hpp"

#include <Thor/Resources/SfmlLoaders.hpp>

#include <pugixml.hpp>
#include <magic_enum.hpp>


ResourceManager& ResourceManager::getInstance()
{
    static ResourceManager instance;

    return instance;
}

void ResourceManager::loadResources(const std::string& filename)
{
    if (pugi::xml_document doc; doc.load_file(filename.c_str()))
    {
        if (auto resourcesNode = doc.child("Resources"))
        {
            if (auto texturesNode = resourcesNode.child("Textures"))
            {
                for (auto textureNode : texturesNode.children())
                {
                    auto textureID = magic_enum::enum_cast<TextureID>(textureNode.name());

                    if (textureID.has_value())
                    {
                        loadTexture(textureID.value(), "Resources/Textures/" + std::string(textureNode.text().as_string()));
                    }
                }
            }
        }
    }
}

sf::Texture& ResourceManager::getTexture(TextureID textureID)
{
    return textures[textureID];
}

void ResourceManager::loadTexture(TextureID textureID, const std::string& filename)
{
    textures.acquire(textureID, thor::Resources::fromFile<sf::Texture>(filename));
}