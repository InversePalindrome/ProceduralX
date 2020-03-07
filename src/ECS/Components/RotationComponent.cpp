/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - RotationComponent.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/RotationComponent.hpp"


ECS::Components::RotationComponent::RotationComponent() :
    angle(0.f)
{
}

ECS::Components::RotationComponent::RotationComponent(float angle) :
    angle(angle)
{
}

float ECS::Components::RotationComponent::getAngle() const
{
    return angle;
}

void ECS::Components::RotationComponent::setAngle(float angle)
{
    this->angle = angle;
}