/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - HealthComponent.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/HealthComponent.hpp"


ECS::Components::HealthComponent::HealthComponent() :
    health(1.f)
{
}

ECS::Components::HealthComponent::HealthComponent(float health) :
    health(health)
{
}

float ECS::Components::HealthComponent::getHealth() const
{
    return health;
}

void ECS::Components::HealthComponent::setHealth(float health)
{
    this->health = health;
}