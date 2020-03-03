/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - Map.cpp
https://inversepalindrome.com/
*/


#include "Map.hpp"


Map::Map() :
    width(0.f),
    height(0.f)
{
}

Map::Map(float width, float height) :
    width(width),
    height(height)
{
}

float Map::getWidth() const
{
    return width;
}

void Map::setWidth(float width)
{
    this->width = width;
}

float Map::getHeight() const
{
    return height;
}

void Map::setHeight(float height)
{
    this->height = height;
}