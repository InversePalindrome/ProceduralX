/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SpriteComponent.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/SpriteComponent.hpp"


ECS::Components::SpriteComponent::SpriteComponent() :
    zOrder(0)
{
}

ECS::Components::SpriteComponent::SpriteComponent(const sf::Texture& texture) :
    sprite(texture),
    zOrder(0)
{
}

sf::Sprite& ECS::Components::SpriteComponent::getSprite()
{
    return sprite;
}

const sf::Sprite& ECS::Components::SpriteComponent::getSprite() const
{
    return sprite;
}

void ECS::Components::SpriteComponent::setTexture(const sf::Texture& texture) 
{
    sprite.setTexture(texture, true);
}

void ECS::Components::SpriteComponent::setTextureRect(const sf::IntRect& textureRect)
{
    sprite.setTextureRect(textureRect);
}

void ECS::Components::SpriteComponent::setOriginFromScale(const sf::Vector2f& originScale)
{
    sprite.setOrigin(sprite.getLocalBounds().width * originScale.x, sprite.getLocalBounds().height * originScale.y);
}

int ECS::Components::SpriteComponent::getZOrder() const
{
    return zOrder;
}

void ECS::Components::SpriteComponent::setZOrder(int zOrder)
{
    this->zOrder = zOrder;
}

void ECS::Components::SpriteComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    
    target.draw(sprite, states);
}