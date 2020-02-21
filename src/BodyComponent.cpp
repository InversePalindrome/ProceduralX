/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - BodyComponent.cpp
https://inversepalindrome.com/
*/


#include "BodyComponent.hpp"


BodyComponent::BodyComponent(b2Body* body) :
    body(body)
{
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