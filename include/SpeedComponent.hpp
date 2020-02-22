/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SpeedComponent.hpp
https://inversepalindrome.com/
*/


#pragma once


class SpeedComponent
{
public:
    SpeedComponent();
    SpeedComponent(float linearSpeed, float angularSpeed);

    float getLinearSpeed() const;
    void setLinearSpeed(float linearSpeed);

    float getAngularSpeed() const;
    void setAngularSpeed(float angularSpeed);

private:
    float linearSpeed;
    float angularSpeed;
};