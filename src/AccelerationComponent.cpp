/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - AccelerationComponent.cpp
https://inversepalindrome.com/
*/


#include "AccelerationComponent.hpp"


AccelerationComponent::AccelerationComponent() :
    linearAcceleration(0.f),
    angularAcceleration(0.f)
{
}

AccelerationComponent::AccelerationComponent(float linearAcceleration, float angularAcceleration) :
    linearAcceleration(linearAcceleration),
    angularAcceleration(angularAcceleration)
{
}

float AccelerationComponent::getLinearAcceleration() const
{
    return linearAcceleration;
}

void AccelerationComponent::setLinearAcceleration(float linearAcceleration)
{
    this->linearAcceleration = linearAcceleration;
}

float AccelerationComponent::getAngularAcceleration() const
{
    return angularAcceleration;
}

void AccelerationComponent::setAngularAcceleration(float angularAcceleration)
{
    this->angularAcceleration = angularAcceleration;
}