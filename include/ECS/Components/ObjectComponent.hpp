/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ObjectComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/ObjectType.hpp"


namespace ECS::Components
{
    class ObjectComponent
    {
    public:
        ObjectComponent();

        ObjectType getObjectType() const;
        void setObjectType(ObjectType objectType);

    private:
        ObjectType objectType;
    };
}