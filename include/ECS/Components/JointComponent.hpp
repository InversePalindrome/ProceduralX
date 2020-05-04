/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/JointComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <box2d/b2_body.h>
#include <box2d/b2_world.h>
#include <box2d/b2_joint.h>
#include <box2d/b2_weld_joint.h>
#include <box2d/b2_gear_joint.h>
#include <box2d/b2_motor_joint.h>
#include <box2d/b2_mouse_joint.h>
#include <box2d/b2_distance_joint.h>
#include <box2d/b2_revolute_joint.h>
#include <box2d/b2_friction_joint.h>
#include <box2d/b2_prismatic_joint.h>

#include <variant>


namespace ECS::Components
{
    class JointComponent
    {
    public:
        using JointDefVariant = std::variant<b2JointDef, b2DistanceJointDef, b2WeldJointDef, b2RevoluteJointDef,
            b2FrictionJointDef, b2PrismaticJointDef, b2GearJointDef, b2MotorJointDef, b2MouseJointDef>;

        JointComponent();

        void initialize(b2World& world, b2Body* bodyA, b2Body* bodyB);

        void setInitializationParameter(const JointDefVariant& jointDefVariant);

        b2Joint* getJoint();
        const b2Joint* getJoint() const;

        b2Body* getBodyA();
        const b2Body* getBodyA() const;

        b2Body* getBodyB();
        const b2Body* getBodyB() const;

        std::size_t getEntityIDA() const;
        void setEntityIDA(std::size_t entityIDA);

        std::size_t getEntityIDB() const;
        void setEntityIDB(std::size_t entityIDB);

        b2Vec2 getAnchorA() const;
        b2Vec2 getAnchorB() const;

    private:
        b2Joint* joint;
        JointDefVariant jointDefVariant;

        std::size_t entityIDA;
        std::size_t entityIDB;
    };
}