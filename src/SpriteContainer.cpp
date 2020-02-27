/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SpriteContainer.cpp
https://inversepalindrome.com/
*/


#include "SpriteContainer.hpp"


void SpriteContainer::addSprite(const std::reference_wrapper<SpriteComponent>& sprite)
{
    //sprites.insert(sprite);
}

void SpriteContainer::removeSprite(const std::reference_wrapper<SpriteComponent>& sprite)
{
   // sprites.erase(sprite);
}

void SpriteContainer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    /*
    for (const auto& sprite : sprites)
    {
        target.draw(sprite.get(), states);
    }*/
}