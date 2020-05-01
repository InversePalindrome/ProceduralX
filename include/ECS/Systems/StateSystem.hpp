/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Systems/StateSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/Events.hpp"
#include "ECS/Systems/System.hpp"


namespace ECS::Systems
{
    class StateSystem : public System
    {
    public:
        StateSystem(entt::registry& registry, entt::dispatcher& dispatcher, EntityFactory& entityFactory);

        virtual void update(const App::Seconds& deltaTime) override;

    private:
        void onStateAdded(entt::registry&, entt::entity entity);
        void onChangeState(const ChangeState& event);
    };
}