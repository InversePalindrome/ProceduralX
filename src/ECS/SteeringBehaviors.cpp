/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/SteeringBehaviors.cpp
https://inversepalindrome.com/
*/


#include "ECS/SteeringBehaviors.hpp"
#include "App/Random.hpp"
#include "App/Constants.hpp"

#include <boost/math/constants/constants.hpp>

#include <cmath>


b2Vec2 ECS::SteeringBehaviors::move(const b2Vec2& bodyPosition, Direction direction, const b2Vec2& bodyVelocity, float acceleration, float maxSpeed, float mass)
{
    switch (direction)
    {
    case Direction::Up:
        return { 0.f, mass * (b2Min(bodyVelocity.y + acceleration, maxSpeed) - bodyVelocity.y) };
    case Direction::Down:
        return { 0.f, mass * (b2Max(bodyVelocity.y -acceleration, -maxSpeed) - bodyVelocity.y) };
    case Direction::Right:
        return { mass * (b2Min(bodyVelocity.x + acceleration, maxSpeed) - bodyVelocity.x), 0.f };
    case Direction::Left:
        return { mass * (b2Max(bodyVelocity.x - acceleration, -maxSpeed) - bodyVelocity.x), 0.f };
    default:
        return { 0.f, 0.f };
    }
}

b2Vec2 ECS::SteeringBehaviors::seek(const b2Vec2& bodyPosition, const b2Vec2& targetPosition, const b2Vec2& bodyVelocity, float maxSpeed)
{
    return desiredVelocity(bodyPosition, targetPosition, maxSpeed) - bodyVelocity;
}

b2Vec2 ECS::SteeringBehaviors::flee(const b2Vec2& bodyPosition, const b2Vec2& targetPosition, const b2Vec2& bodyVelocity, float maxSpeed)
{
    return desiredVelocity(targetPosition, bodyPosition, maxSpeed) - bodyVelocity;
}

b2Vec2 ECS::SteeringBehaviors::pursue(const b2Vec2& bodyPosition, const b2Vec2& targetPosition, const b2Vec2& bodyVelocity, const b2Vec2& targetVelocity, float maxSpeed)
{
    auto predictionFrames = (targetPosition - bodyPosition).Length() / maxSpeed;

    return seek(bodyPosition, targetPosition + predictionFrames * targetVelocity, bodyVelocity, maxSpeed);
}

b2Vec2 ECS::SteeringBehaviors::evade(const b2Vec2& bodyPosition, const b2Vec2& targetPosition, const b2Vec2& bodyVelocity, const b2Vec2& targetVelocity, float maxSpeed)
{
    auto predictionFrames = (targetPosition - bodyPosition).Length() / maxSpeed;

    return flee(bodyPosition, targetPosition + predictionFrames * targetVelocity, bodyVelocity, maxSpeed);
}

b2Vec2 ECS::SteeringBehaviors::arrive(const b2Vec2& bodyPosition, const b2Vec2& targetPosition, const b2Vec2& bodyVelocity, float slowRadius, float maxSpeed)
{
    if (auto radius = (targetPosition - bodyPosition).Length(); radius < slowRadius)
    {
        return seek(bodyPosition, targetPosition, bodyVelocity, maxSpeed * radius / slowRadius);
    }

    return seek(bodyPosition, targetPosition, bodyVelocity, maxSpeed);
}

b2Vec2 ECS::SteeringBehaviors::wander(const b2Vec2& bodyPosition, const b2Vec2& bodyVelocity, float wanderDistance, float wanderRadius, float wanderRate, float& wanderAngle, float maxSpeed)
{
    auto wanderCenter = bodyVelocity;
    wanderCenter.Normalize();
    wanderCenter *= wanderDistance;
    wanderCenter += { wanderRadius* std::cos(wanderAngle), wanderRadius* std::sin(wanderAngle) };
 
    wanderAngle += App::Random::get(-1.f, 1.f) * wanderRate;

    return seek(bodyPosition, bodyPosition + wanderCenter, bodyVelocity, maxSpeed);
}

b2Vec2 ECS::SteeringBehaviors::orbit(const b2Vec2& satellitePosition, const b2Vec2& primaryPosition, const b2Vec2& bodyVelocity, float maxSpeed)
{
    auto radius = primaryPosition - satellitePosition;

    auto steeringForce = radius.Skew();
    steeringForce.Normalize();
    steeringForce *= maxSpeed;

    return steeringForce - bodyVelocity;
}

b2Vec2 ECS::SteeringBehaviors::alignForce(const b2Vec2& agentPosition, const std::vector<b2Vec2>& neighborVelocities, float alignmentForce)
{
    b2Vec2 steeringForce(0.f, 0.f);

    for (const auto& neighborVelocity : neighborVelocities)
    {
        steeringForce += neighborVelocity;
    }

    if (!neighborVelocities.empty())
    {
        steeringForce *= 1.f / neighborVelocities.size();
        steeringForce.Normalize();
        steeringForce *= alignmentForce;
    }

    return steeringForce;
}

b2Vec2 ECS::SteeringBehaviors::cohesionForce(const b2Vec2& agentPosition, const std::vector<b2Vec2>& neighborPositions, float cohesionForce)
{
    b2Vec2 steeringForce(0.f, 0.f);

    for (const auto& neighborPosition : neighborPositions)
    {
        steeringForce += neighborPosition;
    }

    if (!neighborPositions.empty())
    {
        steeringForce *= 1.f / neighborPositions.size();
        steeringForce -= agentPosition;
        steeringForce.Normalize();
        steeringForce *= cohesionForce;
    }

    return steeringForce;
}

b2Vec2 ECS::SteeringBehaviors::separateForce(const b2Vec2& agentPosition, const std::vector<b2Vec2>& neighborPositions, float separationForce)
{
    b2Vec2 steeringForce(0.f, 0.f);

    for (const auto& neighborPosition : neighborPositions)
    {
        steeringForce += neighborPosition - agentPosition;
    }

    if (!neighborPositions.empty())
    {
        steeringForce *= -1.f / neighborPositions.size();
        steeringForce.Normalize();
        steeringForce *= separationForce;
    }

    return steeringForce;
}

b2Vec2 ECS::SteeringBehaviors::desiredVelocity(const b2Vec2& bodyPosition, const b2Vec2& targetPosition, float maxSpeed)
{
    auto desiredVelocity = targetPosition - bodyPosition;
    desiredVelocity.Normalize();
    desiredVelocity *= maxSpeed;

    return desiredVelocity;
}

float ECS::SteeringBehaviors::face(float desiredAngle, float bodyAngle, float bodyAngularVelocity, float bodyInertia)
{
    auto nextAngle = bodyAngle + bodyAngularVelocity / App::FRAMES_PER_SECOND;
    auto totalRotation = std::remainderf(desiredAngle - nextAngle, 2 * boost::math::constants::pi<float>());

    return bodyInertia * totalRotation * App::FRAMES_PER_SECOND;
}

float ECS::SteeringBehaviors::face(const b2Vec2& bodyPosition, const b2Vec2& targetPosition, float bodyAngle, float bodyAngularVelocity, float bodyInertia)
{
    auto desiredAngle = std::atan2f(targetPosition.y - bodyPosition.y, targetPosition.x - bodyPosition.x);

    return face(desiredAngle, bodyAngle, bodyAngularVelocity, bodyInertia);
}