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
    void serializeJoint(b2Joint* joint, const pugi::xml_node& jointNode);
    void serializeDistanceJoint(b2DistanceJoint* distanceJoint, const pugi::xml_node& distanceJointNode);
    void serializeWeldJoint(b2WeldJoint* weldJoint, const pugi::xml_node& weldJointNode);
    void serializeRevoluteJoint(b2RevoluteJoint* revoluteJoint, const pugi::xml_node& revoluteJointNode);
    void serializeFrictionJoint(b2FrictionJoint* frictionJoint, const pugi::xml_node& frictionJointNode);
    void serializePrismaticJoint(b2PrismaticJoint* prismaticJoint, const pugi::xml_node& prismaticJointNode);
    void serializeGearJoint(b2GearJoint* gearJoint, const pugi::xml_node& gearJointNode);
    void serializeMotorJoint(b2MotorJoint* motorJoint, const pugi::xml_node& motorJointNode);
    void serializeMouseJoint(b2MouseJoint* mouseJoint, const pugi::xml_node& mouseJointNode);
}