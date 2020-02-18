/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SpriteComponent.cpp
https://inversepalindrome.com/
*/


#include "SpriteComponent.hpp"


SpriteComponent::SpriteComponent(const sf::Texture& texture) :
    sprite(texture)
{
}

void SpriteComponent::setTexture(const sf::Texture& texture)
{
    sprite.setTexture(texture);
}

void SpriteComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(sprite, states);
}