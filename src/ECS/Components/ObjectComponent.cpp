/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ObjectComponent.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/ObjectComponent.hpp"


ECS::Components::ObjectComponent::ObjectComponent() :
    objectType(ObjectType::Enemy)
{
}

ECS::ObjectType ECS::Components::ObjectComponent::getObjectType() const
{
    return objectType;
}

void ECS::Components::ObjectComponent::setObjectType(ObjectType objectType)
{
    this->objectType = objectType;
}