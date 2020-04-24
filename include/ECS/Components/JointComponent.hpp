/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/JointComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <box2d/b2_joint.h>


namespace ECS::Components
{
    class JointComponent
    {
    public:
        JointComponent();

        b2Joint* getJoint();
        const b2Joint* getJoint() const;

    private:
        b2Joint* joint;
    };
}