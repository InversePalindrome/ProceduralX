/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SpriteComponent.cpp
https://inversepalindrome.com/
*/


#include "SpriteComponent.hpp"


SpriteComponent::SpriteComponent(const sf::Sprite& sprite) :
    sprite(sprite)
{
}

void SpriteComponent::setSprite(const sf::Sprite& sprite) 
{
    this->sprite = sprite;
}

void SpriteComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(sprite, states);
}