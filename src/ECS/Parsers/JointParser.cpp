/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Parsers/JointParser.cpp
https://inversepalindrome.com/
*/


#include "ECS/Parsers/JointParser.hpp"


void ECS::Parsers::parseJointDef(b2JointDef& jointDef, const pugi::xml_node& jointNode)
{
    if (auto collideConnectedAttribute = jointNode.attribute("collideConnected"))
    {
        jointDef.collideConnected = collideConnectedAttribute.as_bool();
    }
}

void ECS::Parsers::parseDistanceJointDef(b2DistanceJointDef& distanceJointDef, const pugi::xml_node& distanceJointNode)
{
    parseJointDef(distanceJointDef, distanceJointNode);
    parseAnchorPoints(distanceJointDef, distanceJointNode);
}

void ECS::Parsers::parseWeldJointDef(b2WeldJointDef& weldJointDef, const pugi::xml_node& weldJointNode)
{
    parseJointDef(weldJointDef, weldJointNode);
    parseAnchorPoints(weldJointDef, weldJointNode);
}

void ECS::Parsers::parseRevoluteJointDef(b2RevoluteJointDef& revoluteJointDef, const pugi::xml_node& revoluteJointNode)
{
    parseJointDef(revoluteJointDef, revoluteJointNode);
    parseAnchorPoints(revoluteJointDef, revoluteJointNode);
}

void ECS::Parsers::parseFrictionJointDef(b2FrictionJointDef& frictionJointDef, const pugi::xml_node& frictionJointNode)
{
    parseJointDef(frictionJointDef, frictionJointNode);
    parseAnchorPoints(frictionJointDef, frictionJointNode);
}

void ECS::Parsers::parseGearJointDef(b2GearJointDef& gearJointDef, const pugi::xml_node& gearJointNode)
{
    parseJointDef(gearJointDef, gearJointNode);
}

void ECS::Parsers::parseMotorJointDef(b2MotorJointDef& motorJointDef, const pugi::xml_node& motorJointNode)
{
    parseJointDef(motorJointDef, motorJointNode);
}

void ECS::Parsers::parseMouseJointDef(b2MouseJointDef& mouseJointDef, const pugi::xml_node& mouseJointNode)
{
    parseJointDef(mouseJointDef, mouseJointNode);
}

void ECS::Parsers::parsePrismaticJointDef(b2PrismaticJointDef& prismaticJointDef, const pugi::xml_node& prismaticJointNode)
{
    parseJointDef(prismaticJointDef, prismaticJointNode);
    parseAnchorPoints(prismaticJointDef, prismaticJointNode);
}