/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - TransformComponent.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/TransformComponent.hpp"


ECS::Components::TransformComponent::TransformComponent() :
    position(0.f, 0.f),
    angle(0.f)
{
}

ECS::Components::TransformComponent::TransformComponent(const sf::Vector2f& position, float angle) :
    position(position),
    angle(angle)
{
}

sf::Vector2f ECS::Components::TransformComponent::getPosition() const
{
    return position;
}

void ECS::Components::TransformComponent::setPosition(const sf::Vector2f& position)
{
    this->position = position;
}

float ECS::Components::TransformComponent::getAngle() const
{
    return angle;
}

void ECS::Components::TransformComponent::setAngle(float angle)
{
    this->angle = angle;
}