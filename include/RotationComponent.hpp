/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - RotationComponent.hpp
https://inversepalindrome.com/
*/


#pragma once


class RotationComponent
{
public:
    RotationComponent();
    explicit RotationComponent(float angle);

    float getAngle() const;
    void setAngle(float angle);

private:
    float angle;
};