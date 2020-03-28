/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Map.cpp
https://inversepalindrome.com/
*/


#include "ECS/Map.hpp"


ECS::Map::Map() :
    width(0.f),
    height(0.f)
{
}

ECS::Map::Map(float width, float height) :
    width(width),
    height(height)
{
}

float ECS::Map::getWidth() const
{
    return width;
}

void ECS::Map::setWidth(float width)
{
    this->width = width;
}

float ECS::Map::getHeight() const
{
    return height;
}

void ECS::Map::setHeight(float height)
{
    this->height = height;
}