/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SpeedComponent.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/SpeedComponent.hpp"


ECS::Components::SpeedComponent::SpeedComponent() :
    linearSpeed(0.f),
    angularSpeed(0.f)
{
}

ECS::Components::SpeedComponent::SpeedComponent(float linearSpeed, float angularSpeed) :
    linearSpeed(linearSpeed),
    angularSpeed(angularSpeed)
{

}

float ECS::Components::SpeedComponent::getLinearSpeed() const
{
    return linearSpeed;
}

void ECS::Components::SpeedComponent::setLinearSpeed(float linearSpeed)
{
    this->linearSpeed = linearSpeed;
}

float ECS::Components::SpeedComponent::getAngularSpeed() const
{
    return angularSpeed;
}

void ECS::Components::SpeedComponent::setAngularSpeed(float angularSpeed)
{
    this->angularSpeed = angularSpeed;
}