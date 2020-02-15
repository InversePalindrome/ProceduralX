/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - PositionComponent.cpp
https://inversepalindrome.com/
*/


#include "PositionComponent.hpp"


PositionComponent::PositionComponent() :
    position(0.f, 0.f)
{
}

PositionComponent::PositionComponent(const sf::Vector2f& position) :
    position(position)
{
}

PositionComponent::PositionComponent(float xPosition, float yPosition) :
    position(xPosition, yPosition)
{
}

sf::Vector2f PositionComponent::getPosition() const
{
    return position;
}

void PositionComponent::setPosition(const sf::Vector2f& position)
{
    this->position = position;
}