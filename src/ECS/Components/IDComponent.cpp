/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/IDComponent.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/IDComponent.hpp"


ECS::Components::IDComponent::IDComponent() :
    id(0)
{
}

ECS::Components::IDComponent::IDComponent(std::size_t id) :
    id(id)
{
}

std::size_t ECS::Components::IDComponent::getID() const
{
    return id;
}

void ECS::Components::IDComponent::setID(std::size_t id)
{
    this->id = id;
}