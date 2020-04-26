/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/DestructionManager.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <box2d/b2_world_callbacks.h>

#include <entt/entt.hpp>


namespace ECS
{
    class DestructionManager : public b2DestructionListener
    {
    public:
        explicit DestructionManager(entt::registry& registry);
        DestructionManager(const DestructionManager&) = delete;
        DestructionManager& operator=(const DestructionManager&) = delete;
        DestructionManager(DestructionManager&&) = delete;
        DestructionManager& operator=(DestructionManager&&) = delete;

    private:
        entt::registry& registry;

        virtual void SayGoodbye(b2Joint* joint) override;
        virtual void SayGoodbye(b2Fixture* fixture) override;
    };
}