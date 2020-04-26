/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/JointComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <box2d/b2_joint.h>

#include <entt/entt.hpp>


namespace ECS::Components
{
    class JointComponent
    {
    public:
        JointComponent();

        b2Joint* getJoint();
        const b2Joint* getJoint() const;

        b2Body* getBodyA();
        const b2Body* getBodyA() const;

        b2Body* getBodyB();
        const b2Body* getBodyB() const;

        entt::entity getEntityA() const;
        void setEntityA(entt::entity entityA);

        entt::entity getEntityB() const;
        void setEntityB(entt::entity entityB);

        b2Vec2 getAnchorA() const;
        b2Vec2 getAnchorB() const;

    private:
        b2Joint* joint;

        entt::entity entityA;
        entt::entity entityB;
    };
}