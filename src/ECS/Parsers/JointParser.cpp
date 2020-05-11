/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Parsers/JointParser.cpp
https://inversepalindrome.com/
*/


#include "ECS/Parsers/JointParser.hpp"


void ECS::Parsers::parseJointDef(b2JointDef& jointDef, const pugi::xml_node& jointNode)
{
    parseCollideConnected(jointDef, jointNode);
}

void ECS::Parsers::parseDistanceJointDef(b2DistanceJointDef& distanceJointDef, const pugi::xml_node& distanceJointNode)
{
    parseCollideConnected(distanceJointDef, distanceJointNode);
    parseFrequency(distanceJointDef, distanceJointNode);
    parseDampingRatio(distanceJointDef, distanceJointNode);
    parseAnchorPoints(distanceJointDef, distanceJointNode);

    if (auto lengthAttribute = distanceJointNode.attribute("length"))
    {
        distanceJointDef.length = lengthAttribute.as_float();
    }
}

void ECS::Parsers::parseWeldJointDef(b2WeldJointDef& weldJointDef, const pugi::xml_node& weldJointNode)
{
    parseCollideConnected(weldJointDef, weldJointNode);
    parseFrequency(weldJointDef, weldJointNode);
    parseDampingRatio(weldJointDef, weldJointNode);
    parseReferenceAngle(weldJointDef, weldJointNode);
    parseAnchorPoints(weldJointDef, weldJointNode);
}

void ECS::Parsers::parseRevoluteJointDef(b2RevoluteJointDef& revoluteJointDef, const pugi::xml_node& revoluteJointNode)
{
    parseCollideConnected(revoluteJointDef, revoluteJointNode);
    parseReferenceAngle(revoluteJointDef, revoluteJointNode);
    parseMotorSpeed(revoluteJointDef, revoluteJointNode);
    parseEnableLimit(revoluteJointDef, revoluteJointNode);
    parseEnableMotor(revoluteJointDef, revoluteJointNode);
    parseAnchorPoints(revoluteJointDef, revoluteJointNode);

    if (auto lowerAngleAttribute = revoluteJointNode.attribute("lowerAngle"))
    {
        revoluteJointDef.lowerAngle = lowerAngleAttribute.as_float();
    }
    if (auto upperAngleAttribute = revoluteJointNode.attribute("upperAngle"))
    {
        revoluteJointDef.upperAngle = upperAngleAttribute.as_float();
    }
}

void ECS::Parsers::parseFrictionJointDef(b2FrictionJointDef& frictionJointDef, const pugi::xml_node& frictionJointNode)
{
    parseCollideConnected(frictionJointDef, frictionJointNode);
    parseMaxForce(frictionJointDef, frictionJointNode);
    parseMaxTorque(frictionJointDef, frictionJointNode);
    parseAnchorPoints(frictionJointDef, frictionJointNode);
}

void ECS::Parsers::parsePrismaticJointDef(b2PrismaticJointDef& prismaticJointDef, const pugi::xml_node& prismaticJointNode)
{
    parseCollideConnected(prismaticJointDef, prismaticJointNode);
    parseReferenceAngle(prismaticJointDef, prismaticJointNode);
    parseMotorSpeed(prismaticJointDef, prismaticJointNode);
    parseEnableLimit(prismaticJointDef, prismaticJointNode);
    parseEnableMotor(prismaticJointDef, prismaticJointNode);
    parseAnchorPoints(prismaticJointDef, prismaticJointNode);

    if (auto maxMotorForceAttribute = prismaticJointNode.attribute("maxMotorForce"))
    {
        prismaticJointDef.maxMotorForce = maxMotorForceAttribute.as_float();
    }
    if (auto upperTranslationAttribute = prismaticJointNode.attribute("upperTranslation"))
    {
        prismaticJointDef.upperTranslation = upperTranslationAttribute.as_float();
    }
    if (auto lowerTranslationAttribute = prismaticJointNode.attribute("lowerTranslation"))
    {
        prismaticJointDef.lowerTranslation = lowerTranslationAttribute.as_float();
    }
    if (auto localAxisXAttribute = prismaticJointNode.attribute("localAxisX"),
        localAxisYAttribute = prismaticJointNode.attribute("localAxisY");
        localAxisXAttribute && localAxisYAttribute)
    {
        prismaticJointDef.localAxisA = { localAxisXAttribute.as_float(), localAxisYAttribute.as_float() };
    }
}

void ECS::Parsers::parseGearJointDef(b2GearJointDef& gearJointDef, const pugi::xml_node& gearJointNode)
{
    parseCollideConnected(gearJointDef, gearJointNode);

    if (auto ratioAttribute = gearJointNode.attribute("ratio"))
    {
        gearJointDef.ratio = ratioAttribute.as_float();
    }
}

void ECS::Parsers::parseMotorJointDef(b2MotorJointDef& motorJointDef, const pugi::xml_node& motorJointNode)
{
    parseCollideConnected(motorJointDef, motorJointNode);
    parseMaxForce(motorJointDef, motorJointNode);
    parseMaxTorque(motorJointDef, motorJointNode);

    if (auto correctionFactorAttribute = motorJointNode.attribute("correctionFactor"))
    {
        motorJointDef.correctionFactor = correctionFactorAttribute.as_float();
    }
    if (auto linearOffsetXAttribute = motorJointNode.attribute("linearOffsetX"),
        linearOffsetYAttribute = motorJointNode.attribute("linearOffsetY");
        linearOffsetXAttribute && linearOffsetYAttribute)
    {
        motorJointDef.linearOffset = { linearOffsetXAttribute.as_float(), linearOffsetYAttribute.as_float() };
    }
    if (auto angularOffsetAttribute = motorJointNode.attribute("angularOffset"))
    {
        motorJointDef.angularOffset = angularOffsetAttribute.as_float();
    }
}

void ECS::Parsers::parseMouseJointDef(b2MouseJointDef& mouseJointDef, const pugi::xml_node& mouseJointNode)
{
    parseCollideConnected(mouseJointDef, mouseJointNode);
    parseFrequency(mouseJointDef, mouseJointNode);
    parseDampingRatio(mouseJointDef, mouseJointNode);
    parseMaxForce(mouseJointDef, mouseJointNode);

    if (auto targetXAttribute = mouseJointNode.attribute("targetX"),
        targetYAttribute = mouseJointNode.attribute("targetY");
        targetXAttribute && targetYAttribute)
    {
        mouseJointDef.target = { targetXAttribute.as_float(), targetYAttribute.as_float() };
    }
}