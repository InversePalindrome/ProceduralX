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
    BodyComponent();
    explicit BodyComponent(b2Body* body);

    b2Body* getBody();
    void setBody(b2Body* body);

    b2Vec2 getPosition() const;
    void setPosition(const b2Vec2& position);

    float getAngle() const;
    void setAngle(float angle);

    b2Vec2 getLinearVelocity() const;
    void setLinearVelocity(const b2Vec2& linearVelocity);

    float getAngularVelocity() const;
    void setAngularVelocity(float angularVelocity);

    float getMass() const;
    float getInertia() const;

    b2AABB getAABB() const;

    void applyLinearImpulse(const b2Vec2& impulse);
    void applyAngularImpulse(float impulse);

    void* getUserData() const; 
    void setUserData(void* userData);

private:
    b2Body* body;
    b2AABB AABB;

    void computeAABB();
};