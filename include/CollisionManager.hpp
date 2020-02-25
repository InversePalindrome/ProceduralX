/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - CollisionManager.hpp
https://inversepalindrome.com/
*/


#pragma once


#include <box2d/b2_world_callbacks.h>
#include <box2d/b2_contact_manager.h>

#include <entt/entt.hpp>


class CollisionManager : public b2ContactListener
{
public:
    explicit CollisionManager(entt::dispatcher& dispatcher);
    CollisionManager(const CollisionManager&) = delete;
    CollisionManager& operator= (const CollisionManager&) = delete;
    CollisionManager(CollisionManager&&) = delete;
    CollisionManager& operator=(CollisionManager&&) = delete;

private:
    entt::dispatcher& dispatcher;

    virtual void BeginContact(b2Contact* contact) override;
    virtual void EndContact(b2Contact* contact) override;

    virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold) override;
    virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) override;
};