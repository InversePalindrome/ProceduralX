/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/CollisionManager.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/ObjectType.hpp"

#include <box2d/b2_contact.h>
#include <box2d/b2_world_callbacks.h>
#include <box2d/b2_contact_manager.h>

#include <entt/entt.hpp>

#include <optional>


namespace ECS
{
    class CollisionManager : public b2ContactListener
    {
    public:
        CollisionManager(entt::registry& registry, entt::dispatcher& dispatcher);
        CollisionManager(const CollisionManager&) = delete;
        CollisionManager& operator= (const CollisionManager&) = delete;
        CollisionManager(CollisionManager&&) = delete;
        CollisionManager& operator=(CollisionManager&&) = delete;

    private:
        entt::registry& registry;
        entt::dispatcher& dispatcher;

        virtual void BeginContact(b2Contact* contact) override;
        virtual void EndContact(b2Contact* contact) override;

        virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold) override;
        virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) override;
    };

    std::optional<std::pair<entt::entity, entt::entity>> getCollisionPair(entt::entity entityA, entt::entity entityB,
        flags::flags<ObjectType> objectTypeA, flags::flags<ObjectType> objectTypeB,
        flags::flags<ObjectType> orderedObjectTypeA, flags::flags<ObjectType> orderedObjectTypeB);

    entt::entity castUserDataToEntity(void* userData);

    bool isCollisionPairValid(const entt::registry& registry, entt::entity entityA, entt::entity entityB);
}