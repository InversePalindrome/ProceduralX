/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/SatelliteComponent.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/SatelliteComponent.hpp"


ECS::Components::SatelliteComponent::SatelliteComponent() :
    primaryEntityID(0),
    direction(RotationDirection::Clockwise)
{
}

std::size_t ECS::Components::SatelliteComponent::getPrimaryEntityID() const
{
    return primaryEntityID;
}

void ECS::Components::SatelliteComponent::setPrimaryEntityID(std::size_t primaryEntityID)
{
    this->primaryEntityID = primaryEntityID;
}

ECS::RotationDirection ECS::Components::SatelliteComponent::getDirection() const
{
    return direction;
}

void ECS::Components::SatelliteComponent::setDirection(RotationDirection direction)
{
    this->direction = direction;
}