/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - RotationComponent.cpp
https://inversepalindrome.com/
*/


#include "RotationComponent.hpp"


RotationComponent::RotationComponent() :
    angle(0.f)
{
}

RotationComponent::RotationComponent(float angle) :
    angle(angle)
{
}

float RotationComponent::getAngle() const
{
    return angle;
}

void RotationComponent::setAngle(float angle)
{
    this->angle = angle;
}