/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Systems/OrbitalSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/Systems/System.hpp"

#include <unordered_map>


namespace ECS::Systems
{
    class OrbitalSystem : public System
    {
    public:
        OrbitalSystem(entt::registry& registry, entt::dispatcher& dispatcher, EntityFactory& entityFactory);

        virtual void update(const App::Seconds& deltaTime) override;

        void onIDAdded(entt::registry&, entt::entity);

    private:
        std::unordered_map<std::size_t, entt::entity> idToEntityMap;
    };
}