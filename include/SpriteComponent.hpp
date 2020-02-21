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
    SpriteComponent() = default;
    explicit SpriteComponent(const sf::Texture& texture);

    void setTexture(const sf::Texture& texture);

private:
    sf::Sprite sprite;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};