/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/SatelliteComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/Direction.hpp"

#include <cstddef>


namespace ECS::Components
{
    class SatelliteComponent
    {
    public:
        SatelliteComponent();

        std::size_t getPrimaryEntityID() const;
        void setPrimaryEntityID(std::size_t primaryEntityID);

        RotationDirection getDirection() const;
        void setDirection(RotationDirection direction);

    private:
        std::size_t primaryEntityID;
        RotationDirection direction;
    };
}