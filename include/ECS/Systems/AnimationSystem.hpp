/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - AnimationSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/Systems/System.hpp"
#include "ECS/Systems/Events.hpp"


namespace ECS::Systems
{
    class AnimationSystem : public System
    {
    public:
        AnimationSystem(entt::registry& registry, entt::dispatcher& dispatcher, EntityFactory& entityFactory);

        virtual void update(const App::Seconds& deltaTime) override;

    private:
        void onStateChanged(const StateChanged& event);
    };
}