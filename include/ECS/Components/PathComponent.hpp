/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/PathComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <box2d/b2_math.h>

#include <vector>


namespace ECS::Components
{
    class PathComponent
    {
    public:
        void addPoint(const b2Vec2& position);
        void insertPoint(const b2Vec2& position, std::size_t index);

        void removePoint(std::size_t index);
        void clearPoints();

        b2Vec2& operator[](std::size_t index);
        const b2Vec2& operator[](std::size_t index) const;

        std::size_t getNumberOfPoints() const;

        bool hasPoints() const;

        std::vector<b2Vec2>::iterator begin();
        std::vector<b2Vec2>::iterator end();

        std::vector<b2Vec2>::const_iterator begin() const;
        std::vector<b2Vec2>::const_iterator end() const;

    private:
        std::vector<b2Vec2> pathPoints;
    };
}