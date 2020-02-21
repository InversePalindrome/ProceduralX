/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - BodyComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <box2d/b2_body.h>


class BodyComponent
{
public:
    explicit BodyComponent(b2Body* body);

    b2Vec2 getPosition() const;
    void setPosition(const b2Vec2& position);

    float getAngle() const;
    void setAngle(float angle);

private:
    b2Body* body;
};