/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/PathComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <box2d/b2_math.h>

#include <vector>
#include <unordered_map>


namespace ECS::Components
{
    class PathComponent
    {
    public:
        void addEntityToPath(std::size_t entityID, std::size_t startingIndex = 0);
        void removeEntityFromPath(std::size_t entityID);

        std::size_t getCurrentPointIndex(std::size_t entityID) const;
        void setCurrentPointIndex(std::size_t entityID, std::size_t pointIndex);

        void moveToNextPointIndex(std::size_t entityID);

        const std::unordered_map<std::size_t, std::size_t>& getEntityIDToPointIndexMap() const;

        bool doesEntityUsePath(std::size_t entityID) const;

        void addPoint(const b2Vec2& position);
        void insertPoint(const b2Vec2& position, std::size_t index);

        void removePoint(std::size_t index);
        void clearPoints();

        const std::vector<b2Vec2>& getPathPoints() const;

        bool hasPoints() const;

    private:
        std::vector<b2Vec2> pathPoints;
        std::unordered_map<std::size_t, std::size_t> entityToPointIndexMap;
    };
}