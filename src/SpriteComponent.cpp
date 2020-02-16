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

void SpriteComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}