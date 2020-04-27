/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/SatelliteComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/Direction.hpp"

#include <entt/entt.hpp>


namespace ECS::Components
{
    class SatelliteComponent
    {
    public:
        SatelliteComponent();

        entt::entity getPrimaryEntity() const;
        void setPrimaryEntity(entt::entity primaryEntity);

        RotationDirection getDirection() const;
        void setDirection(RotationDirection direction);

    private:
        entt::entity primaryEntity;
        RotationDirection direction;
    };
}