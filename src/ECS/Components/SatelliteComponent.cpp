/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/SatelliteComponent.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/SatelliteComponent.hpp"


ECS::Components::SatelliteComponent::SatelliteComponent() :
    primaryEntity(entt::null),
    direction(RotationDirection::Clockwise)
{
}

entt::entity ECS::Components::SatelliteComponent::getPrimaryEntity() const
{
    return primaryEntity;
}

void ECS::Components::SatelliteComponent::setPrimaryEntity(entt::entity primaryEntity)
{
    this->primaryEntity = primaryEntity;
}

ECS::RotationDirection ECS::Components::SatelliteComponent::getDirection() const
{
    return direction;
}

void ECS::Components::SatelliteComponent::setDirection(RotationDirection direction)
{
    this->direction = direction;
}