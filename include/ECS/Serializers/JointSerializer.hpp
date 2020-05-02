/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Serializers/JointSerializer.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <box2d/b2_joint.h>
#include <box2d/b2_weld_joint.h>
#include <box2d/b2_gear_joint.h>
#include <box2d/b2_motor_joint.h>
#include <box2d/b2_mouse_joint.h>
#include <box2d/b2_distance_joint.h>
#include <box2d/b2_revolute_joint.h>
#include <box2d/b2_friction_joint.h>
#include <box2d/b2_prismatic_joint.h>

#include <pugixml.hpp>


namespace ECS::Serializers
{
    void serializeJoint(const b2Joint* joint, pugi::xml_node& jointNode);
    void serializeDistanceJoint(const b2DistanceJoint* distanceJoint, pugi::xml_node& distanceJointNode);
    void serializeWeldJoint(const b2WeldJoint* weldJoint, pugi::xml_node& weldJointNode);
    void serializeRevoluteJoint(const b2RevoluteJoint* revoluteJoint, pugi::xml_node& revoluteJointNode);
    void serializeFrictionJoint(const b2FrictionJoint* frictionJoint, pugi::xml_node& frictionJointNode);
    void serializePrismaticJoint(const b2PrismaticJoint* prismaticJoint, pugi::xml_node& prismaticJointNode);
    void serializeGearJoint(const b2GearJoint* gearJoint, pugi::xml_node& gearJointNode);
    void serializeMotorJoint(const b2MotorJoint* motorJoint, pugi::xml_node& motorJointNode);
    void serializeMouseJoint(const b2MouseJoint* mouseJoint, pugi::xml_node& mouseJointNode);

    template<typename JointPtr>
    void serializeFrequency(const JointPtr joint, pugi::xml_node& jointNode)
    {
        jointNode.append_attribute("frequency") = joint->GetFrequency();
    }

    template<typename JointPtr>
    void serializeDampingRatio(const JointPtr joint, pugi::xml_node& jointNode)
    {
        jointNode.append_attribute("dampingRatio") = joint->GetDampingRatio();
    }

    template<typename JointPtr>
    void serializeMaxForce(const JointPtr joint, pugi::xml_node& jointNode)
    {
        jointNode.append_attribute("maxForce") = joint->GetMaxForce();
    }

    template<typename JointPtr>
    void serializeMaxTorque(const JointPtr joint, pugi::xml_node& jointNode)
    {
        jointNode.append_attribute("maxTorque") = joint->GetMaxTorque();
    }

    template<typename JointPtr>
    void serializeMotorSpeed(const JointPtr joint, pugi::xml_node& jointNode)
    {
        jointNode.append_attribute("motorSpeed") = joint->GetMotorSpeed();
    }

    template<typename JointPtr>
    void serializeReferenceAngle(const JointPtr joint, pugi::xml_node& jointNode)
    {
        jointNode.append_attribute("referenceAngle") = joint->GetReferenceAngle();
    }

    template<typename JointPtr>
    void serializeCollideConnected(const JointPtr joint, pugi::xml_node& jointNode)
    {
        jointNode.append_attribute("collideConnected") = joint->GetCollideConnected();
    }

    template<typename JointPtr>
    void serializeEnableLimit(const JointPtr joint, pugi::xml_node& jointNode)
    {
        jointNode.append_attribute("enableLimit") = joint->IsLimitEnabled();
    }

    template<typename JointPtr>
    void serializeEnableMotor(const JointPtr joint, pugi::xml_node& jointNode)
    {
        jointNode.append_attribute("enableMotor") = joint->IsMotorEnabled();
    }

    template<typename JointPtr>
    void serializeAnchorPoints(const JointPtr joint, pugi::xml_node& jointNode)
    {
        jointNode.append_attribute("anchorAX") = joint->GetLocalAnchorA().x;
        jointNode.append_attribute("anchorAY") = joint->GetLocalAnchorA().y;

        jointNode.append_attribute("anchorBX") = joint->GetLocalAnchorB().x;
        jointNode.append_attribute("anchorBY") = joint->GetLocalAnchorB().y;
    }
}