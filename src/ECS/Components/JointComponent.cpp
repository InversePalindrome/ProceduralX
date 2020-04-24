/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/JointComponent.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/JointComponent.hpp"


ECS::Components::JointComponent::JointComponent() :
    joint(nullptr)
{
}

b2Joint* ECS::Components::JointComponent::getJoint()
{
    return joint;
}

const b2Joint* ECS::Components::JointComponent::getJoint() const
{
    return joint;
}