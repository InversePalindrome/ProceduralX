/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/SpriteComponent.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/SpriteComponent.hpp"


ECS::Components::SpriteComponent::SpriteComponent() :
    originScale(0.f, 0.f),
    textureID(App::TextureID::Null),
    zOrder(0)
{
}

ECS::Components::SpriteComponent::SpriteComponent(App::TextureID textureID, const sf::Texture& texture) :
    sprite(texture),
    textureID(textureID),
    originScale(0.f, 0.f),
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

void ECS::Components::SpriteComponent::setTexture(sf::Texture& texture)
{
    sprite.setTexture(texture);
}

App::TextureID ECS::Components::SpriteComponent::getTextureID() const
{
    return textureID;
}

void ECS::Components::SpriteComponent::setTextureID(App::TextureID textureID)
{
    this->textureID = textureID;
}

sf::IntRect ECS::Components::SpriteComponent::getTextureRect() const
{
    return sprite.getTextureRect();
}

void ECS::Components::SpriteComponent::setTextureRect(const sf::IntRect& textureRect)
{
    sprite.setTextureRect(textureRect);
}

sf::Vector2f ECS::Components::SpriteComponent::getOriginScale() const
{
    return originScale;
}

void ECS::Components::SpriteComponent::setOriginScale(const sf::Vector2f& originScale)
{
    this->originScale = originScale;

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