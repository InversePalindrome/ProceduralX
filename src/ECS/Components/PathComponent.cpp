/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/PathComponent.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/PathComponent.hpp"


void ECS::Components::PathComponent::addPoint(const b2Vec2& position)
{
    pathPoints.push_back(position);
}

void ECS::Components::PathComponent::insertPoint(const b2Vec2& position, std::size_t index)
{
    pathPoints.insert(pathPoints.begin() + index, position);
}

void ECS::Components::PathComponent::removePoint(std::size_t index)
{
    pathPoints.erase(pathPoints.begin() + index);
}

void ECS::Components::PathComponent::clearPoints()
{
    pathPoints.clear();
}

b2Vec2& ECS::Components::PathComponent::operator[](std::size_t index)
{
    return pathPoints[index];
}

const b2Vec2& ECS::Components::PathComponent::operator[](std::size_t index) const
{
    return pathPoints[index];
}

std::size_t ECS::Components::PathComponent::getNumberOfPoints() const
{
    return pathPoints.size();
}

bool ECS::Components::PathComponent::hasPoints() const
{
    return !pathPoints.empty();
}

std::vector<b2Vec2>::iterator ECS::Components::PathComponent::begin()
{
    return pathPoints.begin();
}

std::vector<b2Vec2>::iterator ECS::Components::PathComponent::end()
{
    return pathPoints.end();
}

std::vector<b2Vec2>::const_iterator ECS::Components::PathComponent::begin() const
{
    return pathPoints.cbegin();
}

std::vector<b2Vec2>::const_iterator ECS::Components::PathComponent::end() const
{
    return pathPoints.cend();
}