/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/AccelerationComponent.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/AccelerationComponent.hpp"


ECS::Components::AccelerationComponent::AccelerationComponent() :
    linearAcceleration(0.f),
    angularAcceleration(0.f)
{
}

ECS::Components::AccelerationComponent::AccelerationComponent
(float linearAcceleration, float angularAcceleration) :
    linearAcceleration(linearAcceleration),
    angularAcceleration(angularAcceleration)
{
}

float ECS::Components::AccelerationComponent::getLinearAcceleration() const
{
    return linearAcceleration;
}

void ECS::Components::AccelerationComponent::setLinearAcceleration(float linearAcceleration)
{
    this->linearAcceleration = linearAcceleration;
}

float ECS::Components::AccelerationComponent::getAngularAcceleration() const
{
    return angularAcceleration;
}

void ECS::Components::AccelerationComponent::setAngularAcceleration(float angularAcceleration)
{
    this->angularAcceleration = angularAcceleration;
}