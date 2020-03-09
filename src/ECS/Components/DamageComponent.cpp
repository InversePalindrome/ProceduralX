/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - DamageComponent.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/DamageComponent.hpp"


ECS::Components::DamageComponent::DamageComponent() :
    damage(1.f)
{
}

ECS::Components::DamageComponent::DamageComponent(float damage) :
    damage(damage)
{
}

float ECS::Components::DamageComponent::getDamage() const
{
    return damage;
}

void ECS::Components::DamageComponent::setDamage(float damage)
{
    this->damage = damage;
}