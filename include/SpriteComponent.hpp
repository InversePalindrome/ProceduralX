/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SpriteComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>


class SpriteComponent : public sf::Transformable, public sf::Drawable
{
public:
    SpriteComponent();
    explicit SpriteComponent(const sf::Texture& texture);

    sf::Sprite& getSprite();
    const sf::Sprite& getSprite() const;

    void setTexture(const sf::Texture& texture);
    void setTextureRect(const sf::IntRect& textureRect);
    void setOriginFromScale(const sf::Vector2f& originScale);

    int getZOrder() const;
    void setZOrder(int zOrder);

private:
    sf::Sprite sprite;
    int zOrder;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};