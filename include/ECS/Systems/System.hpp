/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - System.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "App/Seconds.hpp"
#include "ECS/EntityFactory.hpp"

#include <entt/entt.hpp>


namespace ECS::Systems
{
    class System
    {
    public:
        System(entt::registry& registry, entt::dispatcher& dispatcher, EntityFactory& entityFactory);
        System(const System&) = delete;
        System& operator=(const System&) = delete;
        System(System&&) = delete;
        System& operator=(System&&) = delete;

        virtual ~System() = default;

        virtual void update(const App::Seconds& deltaTime) = 0;

    protected:
        entt::registry& registry;
        entt::dispatcher& dispatcher;
        EntityFactory& entityFactory;
    };
}