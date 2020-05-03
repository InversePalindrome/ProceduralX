/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/JointComponent.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/JointComponent.hpp"


ECS::Components::JointComponent::JointComponent() :
    joint(nullptr),
    entityA(entt::null),
    entityB(entt::null)
{
}

void ECS::Components::JointComponent::initialize(b2World& world, b2Body* bodyA, b2Body* bodyB)
{
    std::visit([this, &world, bodyA, bodyB](auto& jointDef) 
        {
            jointDef.bodyA = bodyA;
            jointDef.bodyB = bodyB;

            joint = world.CreateJoint(&jointDef);
        }, jointDefVariant);
}

void ECS::Components::JointComponent::setInitializationParameter(const JointDefVariant& jointDefVariant)
{
    this->jointDefVariant = jointDefVariant;
}

b2Joint* ECS::Components::JointComponent::getJoint()
{
    return joint;
}

const b2Joint* ECS::Components::JointComponent::getJoint() const
{
    return joint;
}

b2Body* ECS::Components::JointComponent::getBodyA()
{
    return joint->GetBodyA();
}

const b2Body* ECS::Components::JointComponent::getBodyA() const
{
    return joint->GetBodyA();
}

b2Body* ECS::Components::JointComponent::getBodyB()
{
    return joint->GetBodyB();
}

const b2Body* ECS::Components::JointComponent::getBodyB() const
{
    return joint->GetBodyB();
}

entt::entity ECS::Components::JointComponent::getEntityA() const
{
    return entityA;
}

void ECS::Components::JointComponent::setEntityA(entt::entity entityA)
{
    this->entityA = entityA;
}

entt::entity ECS::Components::JointComponent::getEntityB() const
{
    return entityB;
}

void ECS::Components::JointComponent::setEntityB(entt::entity entityB)
{
    this->entityB = entityB;
}

b2Vec2 ECS::Components::JointComponent::getAnchorA() const
{
    return joint->GetAnchorA();
}

b2Vec2 ECS::Components::JointComponent::getAnchorB() const
{
    return joint->GetAnchorB();
}