/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/SpriteComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "App/ResourceID.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>


namespace ECS::Components
{
    class SpriteComponent : public sf::Transformable, public sf::Drawable
    {
    public:
        SpriteComponent();
        SpriteComponent(App::TextureID textureID, const sf::Texture& texture);

        sf::Sprite& getSprite();
        const sf::Sprite& getSprite() const;

        void setTexture(sf::Texture& texture);

        App::TextureID getTextureID() const;
        void setTextureID(App::TextureID textureID);

        sf::IntRect getTextureRect() const;
        void setTextureRect(const sf::IntRect& textureRect);

        sf::Vector2f getOriginScale() const;
        void setOriginScale(const sf::Vector2f& originScale);

        int getZOrder() const;
        void setZOrder(int zOrder);

    private:
        sf::Sprite sprite;
        App::TextureID textureID;

        sf::Vector2f originScale;
        int zOrder;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
}