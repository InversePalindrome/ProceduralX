/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - BodyComponent.cpp
https://inversepalindrome.com/
*/


#include "BodyComponent.hpp"

#include <box2d/b2_fixture.h>


BodyComponent::BodyComponent() :
    body(nullptr),
    AABB({ {FLT_MAX, FLT_MAX}, {-FLT_MAX, -FLT_MAX} })
{
}

BodyComponent::BodyComponent(b2Body* body) :
    body(body)
{
    computeAABB();
}

b2Body* BodyComponent::getBody()
{
    return body;
}

void BodyComponent::setBody(b2Body* body)
{
    this->body = body;

    computeAABB();
}

b2Vec2 BodyComponent::getPosition() const
{
    return body->GetPosition();
}

void BodyComponent::setPosition(const b2Vec2& position)
{
    body->SetTransform(position, body->GetAngle());
}

float BodyComponent::getAngle() const
{
    return body->GetAngle();
}

void BodyComponent::setAngle(float angle)
{
    body->SetTransform(body->GetPosition(), angle);
}

b2Vec2 BodyComponent::getLinearVelocity() const
{
    return body->GetLinearVelocity();
}

void BodyComponent::setLinearVelocity(const b2Vec2& linearVelocity)
{
    body->SetLinearVelocity(linearVelocity);
}

float BodyComponent::getAngularVelocity() const
{
    return body->GetAngularVelocity();
}

void BodyComponent::setAngularVelocity(float angularVelocity)
{
    body->SetAngularVelocity(angularVelocity);
}

float BodyComponent::getMass() const
{
    return body->GetMass();
}

float BodyComponent::getInertia() const
{
    return body->GetInertia();
}

b2AABB BodyComponent::getAABB() const
{
    return AABB;
}

void BodyComponent::applyLinearImpulse(const b2Vec2& impulse)
{
    body->ApplyLinearImpulse(impulse, body->GetWorldCenter(), true);
}

void BodyComponent::applyAngularImpulse(float impulse)
{
    body->ApplyAngularImpulse(impulse, true);
}

void* BodyComponent::getUserData() const
{
    return body->GetUserData();
}

void BodyComponent::setUserData(void* userData)
{
    body->SetUserData(userData);
}

void BodyComponent::computeAABB()
{
    for (auto* fixture = body->GetFixtureList(); fixture; fixture = fixture->GetNext())
    {
        for (int child = 0; child < fixture->GetShape()->GetChildCount(); ++child)
        {
            b2Transform transform;
            transform.SetIdentity();

            b2AABB shapeAABB{ { FLT_MAX, FLT_MAX },{ -FLT_MAX, -FLT_MAX } };
            fixture->GetShape()->ComputeAABB(&shapeAABB, transform, child);

            AABB.Combine(shapeAABB);
        }
    }
}