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

private:
    b2Body* body;
};