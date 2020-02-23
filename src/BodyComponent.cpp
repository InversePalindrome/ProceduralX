/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - BodyComponent.cpp
https://inversepalindrome.com/
*/


#include "BodyComponent.hpp"


BodyComponent::BodyComponent() :
    body(nullptr)
{
}

BodyComponent::BodyComponent(b2Body* body) :
    body(body)
{
}

b2Body* BodyComponent::getBody()
{
    return body;
}

void BodyComponent::setBody(b2Body* body)
{
    this->body = body;
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