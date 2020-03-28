/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - App/ResourceManager.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "App/ResourceID.hpp"

#include <Thor/Resources/ResourceHolder.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include <pugixml.hpp>

#include <magic_enum.hpp>

#include <functional>
#include <unordered_map>


namespace App
{
    class ResourceManager
    {
    public:
        static ResourceManager& getInstance();

        ResourceManager(const ResourceManager&) = delete;
        ResourceManager& operator=(const ResourceManager&) = delete;
        ResourceManager(ResourceManager&&) = delete;
        ResourceManager& operator=(ResourceManager&&) = delete;

        void loadResources(const std::string& filename);

        sf::Texture& getTexture(TextureID textureID);
        sf::Image& getImage(ImageID imageID);
        sf::Font& getFont(FontID fontID);
        sf::SoundBuffer& getSoundBuffer(SoundID soundID);

    private:
        ResourceManager();

        thor::ResourceHolder<sf::Texture, TextureID> textures;
        thor::ResourceHolder<sf::Image, ImageID> images;
        thor::ResourceHolder<sf::Font, FontID> fonts;
        thor::ResourceHolder<sf::SoundBuffer, SoundID> sounds;

        std::unordered_map<std::string, std::function<void(std::size_t, const std::string&,
            const pugi::xml_node&)>> resourceLoaders;

        template<typename ResourceType>
        void loadResources(const pugi::xml_node& resourcesNode, const std::string& resourceType);
    };

    template<typename ResourceType>
    void ResourceManager::loadResources(const pugi::xml_node& resourcesNode, const std::string& resourceType)
    {
        for (auto resourceNode : resourcesNode.children())
        {
            auto resourceIDOptional = magic_enum::enum_cast<ResourceType>(resourceNode.name());

            if (resourceIDOptional.has_value())
            {
                auto resourceIntegerID = magic_enum::enum_integer(resourceIDOptional.value());

                resourceLoaders[resourceType](resourceIntegerID, "Resources/" + resourceType + '/'
                    + std::string(resourceNode.text().as_string()), resourceNode);
            }
        }
    }
}