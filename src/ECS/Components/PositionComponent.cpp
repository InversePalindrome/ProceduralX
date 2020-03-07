/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - PositionComponent.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/PositionComponent.hpp"


ECS::Components::PositionComponent::PositionComponent() :
    position(0.f, 0.f)
{
}

ECS::Components::PositionComponent::PositionComponent(const sf::Vector2f& position) :
    position(position)
{
}

ECS::Components::PositionComponent::PositionComponent(float xPosition, float yPosition) :
    position(xPosition, yPosition)
{
}

sf::Vector2f ECS::Components::PositionComponent::getPosition() const
{
    return position;
}

void ECS::Components::PositionComponent::setPosition(const sf::Vector2f& position)
{
    this->position = position;
}