/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Serializers/JointSerializer.cpp
https://inversepalindrome.com/
*/


#include "ECS/Serializers/JointSerializer.hpp"


void ECS::Serializers::serializeJoint(const b2Joint* joint, pugi::xml_node& jointNode)
{
    jointNode.append_attribute("type") = "Joint";

    serializeCollideConnected(joint, jointNode);
}

void ECS::Serializers::serializeDistanceJoint(const b2DistanceJoint* distanceJoint, pugi::xml_node& distanceJointNode)
{
    distanceJointNode.append_attribute("type") = "DistanceJoint";

    serializeCollideConnected(distanceJoint, distanceJointNode);
    serializeFrequency(distanceJoint, distanceJointNode);
    serializeDampingRatio(distanceJoint, distanceJointNode);
    serializeAnchorPoints(distanceJoint, distanceJointNode);
}

void ECS::Serializers::serializeWeldJoint(const b2WeldJoint* weldJoint, pugi::xml_node& weldJointNode)
{
    weldJointNode.append_attribute("type") = "WeldJoint";

    serializeCollideConnected(weldJoint, weldJointNode);
    serializeFrequency(weldJoint, weldJointNode);
    serializeDampingRatio(weldJoint, weldJointNode);
    serializeReferenceAngle(weldJoint, weldJointNode);
    serializeAnchorPoints(weldJoint, weldJointNode);
}

void ECS::Serializers::serializeRevoluteJoint(const b2RevoluteJoint* revoluteJoint, pugi::xml_node& revoluteJointNode)
{
    revoluteJointNode.append_attribute("type") = "RevoluteJoint";

    serializeCollideConnected(revoluteJoint, revoluteJointNode);
    serializeReferenceAngle(revoluteJoint, revoluteJointNode);
    serializeMotorSpeed(revoluteJoint, revoluteJointNode);
    serializeEnableLimit(revoluteJoint, revoluteJointNode);
    serializeEnableMotor(revoluteJoint, revoluteJointNode);
    serializeAnchorPoints(revoluteJoint, revoluteJointNode);

    revoluteJointNode.append_attribute("lowerAngle") = revoluteJoint->GetJointAngle();
    revoluteJointNode.append_attribute("upperAngle") = revoluteJoint->GetJointAngle();
}

void ECS::Serializers::serializeFrictionJoint(const b2FrictionJoint* frictionJoint, pugi::xml_node& frictionJointNode)
{
    frictionJointNode.append_attribute("type") = "FrictionJoint";

    serializeCollideConnected(frictionJoint, frictionJointNode);
    serializeMaxForce(frictionJoint, frictionJointNode);
    serializeMaxTorque(frictionJoint, frictionJointNode);
    serializeAnchorPoints(frictionJoint, frictionJointNode);
}

void ECS::Serializers::serializePrismaticJoint(const b2PrismaticJoint* prismaticJoint, pugi::xml_node& prismaticJointNode)
{
    prismaticJointNode.append_attribute("type") = "PrismaticJoint";

    serializeCollideConnected(prismaticJoint, prismaticJointNode);
    serializeReferenceAngle(prismaticJoint, prismaticJointNode);
    serializeMotorSpeed(prismaticJoint, prismaticJointNode);
    serializeEnableLimit(prismaticJoint, prismaticJointNode);
    serializeAnchorPoints(prismaticJoint, prismaticJointNode);

    prismaticJointNode.append_attribute("maxMotorForce") = prismaticJoint->GetMaxMotorForce();
    prismaticJointNode.append_attribute("upperTranslation") = prismaticJoint->GetUpperLimit();
    prismaticJointNode.append_attribute("lowerTranslation") = prismaticJoint->GetLowerLimit();
    prismaticJointNode.append_attribute("localAxisX") = prismaticJoint->GetLocalAxisA().x;
    prismaticJointNode.append_attribute("localAxisY") = prismaticJoint->GetLocalAxisA().y;
}

void ECS::Serializers::serializeGearJoint(const b2GearJoint* gearJoint, pugi::xml_node& gearJointNode)
{
    gearJointNode.append_attribute("type") = "GearJoint";

    serializeCollideConnected(gearJoint, gearJointNode);

    gearJointNode.append_attribute("ratio") = gearJoint->GetRatio();
}

void ECS::Serializers::serializeMotorJoint(const b2MotorJoint* motorJoint, pugi::xml_node& motorJointNode)
{
    motorJointNode.append_attribute("type") = "MotorJoint";

    serializeCollideConnected(motorJoint, motorJointNode);
    serializeMaxForce(motorJoint, motorJointNode);
    serializeMaxTorque(motorJoint, motorJointNode);

    motorJointNode.append_attribute("correctionFactor") = motorJoint->GetCorrectionFactor();
    motorJointNode.append_attribute("linearOffsetX") = motorJoint->GetLinearOffset().x;
    motorJointNode.append_attribute("linearOffsetY") = motorJoint->GetLinearOffset().y;
    motorJointNode.append_attribute("angularOffset") = motorJoint->GetAngularOffset();
}

void ECS::Serializers::serializeMouseJoint(const b2MouseJoint* mouseJoint, pugi::xml_node& mouseJointNode)
{
    mouseJointNode.append_attribute("type") = "MouseJoint";

    serializeCollideConnected(mouseJoint, mouseJointNode);
    serializeFrequency(mouseJoint, mouseJointNode);
    serializeDampingRatio(mouseJoint, mouseJointNode);
    serializeMaxForce(mouseJoint, mouseJointNode);

    mouseJointNode.append_attribute("targetX") = mouseJoint->GetTarget().x;
    mouseJointNode.append_attribute("targetY") = mouseJoint->GetTarget().y;
}