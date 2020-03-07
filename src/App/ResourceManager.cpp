/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ResourceManager.cpp
https://inversepalindrome.com/
*/


#include "App/ResourceManager.hpp"

#include <Thor/Resources/SfmlLoaders.hpp>


App::ResourceManager& App::ResourceManager::getInstance()
{
    static ResourceManager instance;

    return instance;
}

void App::ResourceManager::loadResources(const std::string& filename)
{
    if (pugi::xml_document doc; doc.load_file(filename.c_str()))
    {
        if (auto resourcesNode = doc.child("Resources"))
        {
            for (auto texturesNode : resourcesNode.children("Textures"))
            {
                loadResources<TextureID>(texturesNode, "Textures");
            }
            for(auto imagesNode : resourcesNode.children("Images"))
            {
                loadResources<ImageID>(imagesNode, "Images");
            }
            for(auto fontsNode : resourcesNode.children("Fonts"))
            {
                loadResources<FontID>(fontsNode, "Fonts");
            }
            for(auto soundsNode : resourcesNode.children("Sounds"))
            {
                loadResources<SoundID>(soundsNode, "Sounds");
            }
        }
    }
}

sf::Texture& App::ResourceManager::getTexture(TextureID textureID)
{
    return textures[textureID];
}

sf::Image& App::ResourceManager::getImage(ImageID imageID)
{
    return images[imageID];
}

sf::Font& App::ResourceManager::getFont(FontID fontID)
{
    return fonts[fontID];
}

sf::SoundBuffer& App::ResourceManager::getSoundBuffer(SoundID soundID)
{
    return sounds[soundID];
}

App::ResourceManager::ResourceManager() :
    resourceLoaders
    ({ 
        {"Textures", [this](auto integerID, const auto& filename, const auto& textureNode) 
        {
            sf::IntRect frameRect;
            
            if (auto leftAttribute = textureNode.attribute("left"),
                topAttribute = textureNode.attribute("top"),
                widthAttribute = textureNode.attribute("width"),
                heightAttribute = textureNode.attribute("height");
                leftAttribute && topAttribute && widthAttribute && heightAttribute)
            {
                frameRect = { leftAttribute.as_int(), topAttribute.as_int(),
                    widthAttribute.as_int(), heightAttribute.as_int() };
            }

            auto& texture = textures.acquire(TextureID{ integerID }, thor::Resources::fromFile<sf::Texture>(filename, frameRect));
            
            if (auto repeatAttribute = textureNode.attribute("repeat"))
            {
                texture.setRepeated(repeatAttribute.as_bool());
            }
        } },
        {"Images", [this](auto integerID, const auto& filename, const auto&)
        {
            images.acquire(ImageID{ integerID }, thor::Resources::fromFile<sf::Image>(filename));
        } } ,
        {"Fonts", [this](auto integerID, const auto& filename, const auto&)
        {
            fonts.acquire(FontID{ integerID }, thor::Resources::fromFile<sf::Font>(filename));
        } } ,
        {"Sounds", [this](auto integerID, const auto& filename, const auto&)
        {
            sounds.acquire(SoundID{ integerID }, thor::Resources::fromFile<sf::SoundBuffer>(filename));
        } } 
    })
{
}