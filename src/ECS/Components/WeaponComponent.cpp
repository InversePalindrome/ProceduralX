/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - WeaponComponent.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/WeaponComponent.hpp"


ECS::Components::WeaponComponent::WeaponComponent() :
    projectile(EntityID::Laser),
    reloadTime(1s)
{
}

ECS::EntityID ECS::Components::WeaponComponent::getProjectile() const
{
    return projectile;
}

void ECS::Components::WeaponComponent::setProjectile(EntityID projectile)
{
    this->projectile = projectile;
}

App::Seconds ECS::Components::WeaponComponent::getReloadTime() const
{
    return reloadTime;
}

void ECS::Components::WeaponComponent::setReloadTime(const App::Seconds& reloadTime)
{
    this->reloadTime = reloadTime;
}