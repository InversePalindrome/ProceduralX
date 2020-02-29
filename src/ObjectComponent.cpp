/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ObjectComponent.cpp
https://inversepalindrome.com/
*/


#include "ObjectComponent.hpp"


ObjectType ObjectComponent::getObjectType() const
{
    return objectType;
}

void ObjectComponent::setObjectType(ObjectType objectType)
{
    this->objectType = objectType;
}