/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Parsers/JointParser.hpp
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


namespace ECS::Parsers
{
    void parseJointDef(b2JointDef& jointDef, const pugi::xml_node& jointNode);
    void parseDistanceJointDef(b2DistanceJointDef& distanceJointDef, const pugi::xml_node& distanceJointNode);
    void parseWeldJointDef(b2WeldJointDef& weldJointDef, const pugi::xml_node& weldJointNode);
    void parseRevoluteJointDef(b2RevoluteJointDef& revoluteJointDef, const pugi::xml_node& revoluteJointNode);
    void parseFrictionJointDef(b2FrictionJointDef& frictionJointDef, const pugi::xml_node& frictionJointNode);
    void parsePrismaticJointDef(b2PrismaticJointDef& prismaticJointDef, const pugi::xml_node& prismaticJointNode);
    void parseGearJointDef(b2GearJointDef& gearJointDef, const pugi::xml_node& gearJointNode);
    void parseMotorJointDef(b2MotorJointDef& motorJointDef, const pugi::xml_node& motorJointNode);
    void parseMouseJointDef(b2MouseJointDef& mouseJointDef, const pugi::xml_node& mouseJointNode);

    template<typename JointDef>
    void parseAnchorPoints(JointDef& jointDef, const pugi::xml_node& jointNode)
    {
        if (auto anchorAXAttribute = jointNode.attribute("anchorAX"),
            anchorAYAttribute = jointNode.attribute("anchorAY");
            anchorAXAttribute && anchorAYAttribute)
        {
            jointDef.localAnchorA = { anchorAXAttribute.as_float(), anchorAYAttribute.as_float() };
        }
        if (auto anchorBXAttribute = jointNode.attribute("anchorBX"),
            anchorBYAttribyte = jointNode.attribute("anchorBY");
            anchorBXAttribute && anchorBYAttribyte)
        {
            jointDef.localAnchorB = { anchorBXAttribute.as_float(), anchorBYAttribyte.as_float() };
        }
    }
}