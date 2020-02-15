/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - VelocityComponent.cpp
https://inversepalindrome.com/
*/


#include "VelocityComponent.hpp"


VelocityComponent::VelocityComponent() :
    velocity(0.f, 0.f)
{
}

VelocityComponent::VelocityComponent(const sf::Vector2f& velocity) :
    velocity(velocity)
{
}

VelocityComponent::VelocityComponent(float xVelocity, float yVelocity) :
    velocity(xVelocity, yVelocity)
{
}

sf::Vector2f VelocityComponent::getVelocity() const
{
    return velocity;
}

void VelocityComponent::setVelocity(const sf::Vector2f& velocity)
{
    this->velocity = velocity;
}