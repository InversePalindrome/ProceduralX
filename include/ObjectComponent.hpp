/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ObjectComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ObjectType.hpp"


class ObjectComponent
{
public:
    ObjectType getObjectType() const;
    void setObjectType(ObjectType objectType);

private:
    ObjectType objectType;
};