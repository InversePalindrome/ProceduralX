/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - StateSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/Systems/System.hpp"
#include "ECS/Systems/Events.hpp"


namespace ECS::Systems
{
    class StateSystem : public System
    {
    public:
        StateSystem(entt::registry& registry, entt::dispatcher& dispatcher, EntityFactory& entityFactory);

        virtual void update(const App::Seconds& deltaTime) override;

    private:
        void onStateAdded(entt::entity entity);
        void onChangeState(const ChangeState& event);
    };
}