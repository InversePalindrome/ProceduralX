/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Systems/OrbitalSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/Systems/System.hpp"


namespace ECS::Systems
{
    class OrbitalSystem : public System
    {
    public:
        OrbitalSystem(entt::registry& registry, entt::dispatcher& dispatcher, EntityFactory& entityFactory);

        virtual void update(const App::Seconds& deltaTime) override;
    };
}