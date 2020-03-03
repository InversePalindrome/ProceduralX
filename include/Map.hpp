/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - Map.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <SFML/System/Vector2.hpp>


class Map
{
public:
    Map();
    Map(float width, float height);

    float getWidth() const;
    void setWidth(float width);

    float getHeight() const;
    void setHeight(float height);

private:
    float width;
    float height;
};