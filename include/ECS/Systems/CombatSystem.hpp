/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Systems/CombatSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/Events.hpp"
#include "ECS/Systems/System.hpp"

#include <cpptime.h>

#include <unordered_map>


namespace ECS::Systems
{
    class CombatSystem : public System
    {
    public:
        CombatSystem(entt::registry& registry, entt::dispatcher& dispatcher, EntityFactory& entityFactory);

        virtual void update(const App::Seconds& deltaTime) override;

    private:
        std::unordered_map<entt::entity, bool> reloadStatusMap;

        CppTime::Timer reloadTimer;

        void onWeaponAdded(entt::registry&, entt::entity entity);
        void onWeaponRemoved(entt::registry&, entt::entity entity);
        void onCombatOccurred(const CombatOccurred& event);
        void onShootProjectile(const ShootProjectile& event);
    };
}