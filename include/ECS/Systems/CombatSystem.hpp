/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - CombatSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/Systems/System.hpp"
#include "ECS/Systems/Events.hpp"

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

        void onWeaponAdded(entt::entity entity);
        void onWeaponRemoved(entt::entity entity);
        void onCombatOccurred(const CombatOccurred& event);
        void onShootProjectile(const ShootProjectile& event);
    };
}