/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SpeedComponent.cpp
https://inversepalindrome.com/
*/


#include "SpeedComponent.hpp"


SpeedComponent::SpeedComponent() :
    linearSpeed(0.f),
    angularSpeed(0.f)
{
}

SpeedComponent::SpeedComponent(float linearSpeed, float angularSpeed) :
    linearSpeed(linearSpeed),
    angularSpeed(angularSpeed)
{

}

float SpeedComponent::getLinearSpeed() const
{
    return linearSpeed;
}

void SpeedComponent::setLinearSpeed(float linearSpeed)
{
    this->linearSpeed = linearSpeed;
}

float SpeedComponent::getAngularSpeed() const
{
    return angularSpeed;
}

void SpeedComponent::setAngularSpeed(float angularSpeed)
{
    this->angularSpeed = angularSpeed;
}