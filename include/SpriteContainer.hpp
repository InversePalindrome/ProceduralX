/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SpriteContainer.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "SpriteComponent.hpp"

#include <SFML/Graphics/Drawable.hpp>

#include <set>
#include <functional>


class SpriteContainer : public sf::Drawable
{
public:
    SpriteContainer() = default;
    SpriteContainer(const SpriteContainer&) = delete;
    SpriteContainer& operator=(const SpriteContainer&) = delete;
    SpriteContainer(SpriteContainer&&) = delete;
    SpriteContainer& operator=(SpriteContainer&&) = delete;

    void addSprite(const std::reference_wrapper<SpriteComponent>& sprite);
    void removeSprite(const std::reference_wrapper<SpriteComponent>& sprite);

private:
    //std::set<std::reference_wrapper<SpriteComponent>> sprites;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};