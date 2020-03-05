/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - PlayerSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "System.hpp"
#include "Events.hpp"


class PlayerSystem : public System
{
public:
    PlayerSystem(entt::registry& registry, entt::dispatcher& dispatcher);

    virtual void update(const Seconds& deltaTime) override;

private:
    entt::entity playerEntity;

    void onPlayerAdded(entt::entity entity);

    void movePlayer(const ActionTriggered& event);
    void rotatePlayer(const MouseMoved& event);
    void shootProjectile(const MousePressed& event);
};