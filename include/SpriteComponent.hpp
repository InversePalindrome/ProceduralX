/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SpriteComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>


class SpriteComponent : public sf::Drawable
{
public:
    explicit SpriteComponent(const sf::Sprite& sprite);

private:
    sf::Sprite sprite;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};