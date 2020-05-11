/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/PathComponent.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/PathComponent.hpp"

#include <limits>


void ECS::Components::PathComponent::addEntityToPath(std::size_t entityID, std::size_t startingIndex)
{
    entityToPointIndexMap.emplace(entityID, startingIndex);
}

void ECS::Components::PathComponent::removeEntityFromPath(std::size_t entityID)
{
    entityToPointIndexMap.erase(entityID);
}

std::size_t ECS::Components::PathComponent::getCurrentPointIndex(std::size_t entityID) const
{
    if (doesEntityUsePath(entityID))
    {
        return entityToPointIndexMap.find(entityID)->second;
    }

    return std::numeric_limits<std::size_t>::max();
}

void ECS::Components::PathComponent::setCurrentPointIndex(std::size_t entityID, std::size_t pointIndex)
{
    entityToPointIndexMap[entityID] = pointIndex;
}

void ECS::Components::PathComponent::moveToNextPointIndex(std::size_t entityID)
{
    auto& currentIndex = entityToPointIndexMap[entityID];

    if (currentIndex == pathPoints.size() - 1)
    {
        currentIndex = 0;
    }
    else
    {
        ++currentIndex;
    }
}

const std::unordered_map<std::size_t, std::size_t>& ECS::Components::PathComponent::getEntityIDToPointIndexMap() const
{
    return entityToPointIndexMap;
}

bool ECS::Components::PathComponent::doesEntityUsePath(std::size_t entityID) const
{
    return entityToPointIndexMap.find(entityID) != entityToPointIndexMap.end();
}

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

const std::vector<b2Vec2>& ECS::Components::PathComponent::getPathPoints() const
{
    return pathPoints;
}

bool ECS::Components::PathComponent::hasPoints() const
{
    return !pathPoints.empty();
}