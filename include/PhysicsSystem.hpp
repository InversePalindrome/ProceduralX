/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - PhysicsSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "Events.hpp"
#include "System.hpp"
#include "CollisionManager.hpp"

#include <box2d/b2_world.h>


class PhysicsSystem : public System
{
public:
    PhysicsSystem(entt::registry& registry, entt::dispatcher& dispatcher);

    virtual void update(const Seconds& deltaTime) override;

private:
    b2World world;
    CollisionManager collisionManager;

    void onMoveEntity(const MoveEntity& event);
    void onRotateEntity(const RotateEntity& event);
    void onBodyAdded(entt::entity entity);
    void onBodyRemoved(entt::entity entity);
};