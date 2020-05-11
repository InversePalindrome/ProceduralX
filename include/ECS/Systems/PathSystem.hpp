/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Systems/PathSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/Systems/System.hpp"
#include "ECS/Events.hpp"


namespace ECS::Systems
{
    class PathSystem : public System
    {
    public:
        PathSystem(entt::registry& registry, entt::dispatcher& dispatcher, EntityFactory& entityFactory);

        virtual void update(const App::Seconds& deltaTime) override;

    private:
        void onCrossedPathPoint(const CrossedPathPoint& event);
    };
}