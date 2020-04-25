/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Systems/PhysicsSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/Systems/System.hpp"
#include "ECS/CollisionManager.hpp"

#include <box2d/b2_world.h>

#include <vector>


namespace ECS::Systems
{
    class PhysicsSystem : public System
    {
    public:
        PhysicsSystem(entt::registry& registry, entt::dispatcher& dispatcher, EntityFactory& entityFactory);

        virtual void update(const App::Seconds& deltaTime) override;

    private:
        b2World world;
        CollisionManager collisionManager;
        std::vector<b2Body*> bodiesToRemove;

        void onBodyAdded(entt::registry&, entt::entity entity);
        void onBodyRemoved(entt::registry&, entt::entity entity);

        void onJointAdded(entt::registry&, entt::entity entity);
        void onJointRemoved(entt::registry&, entt::entity entity);

        void updateEntityRemoval();
        void updateEntityTransforms();
        void updateWorld(const App::Seconds& deltaTime);
    };
}