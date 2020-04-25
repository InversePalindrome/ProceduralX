/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Systems/PlayerSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/Systems/System.hpp"
#include "ECS/Systems/Events.hpp"


namespace ECS::Systems
{
    class PlayerSystem : public System
    {
    public:
        PlayerSystem(entt::registry& registry, entt::dispatcher& dispatcher, EntityFactory& entityFactory);

        virtual void update(const App::Seconds& deltaTime) override;

    private:
        entt::entity playerEntity;

        void onPlayerAdded(entt::registry&, entt::entity entity);

        void movePlayer(const ActionTriggered& event);
        void rotatePlayer(const MouseMoved& event);
        void shootProjectile(const MousePressed& event);
    };
}