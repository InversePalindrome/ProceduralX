/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - InputSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "System.hpp"
#include "Events.hpp"
#include "InputManager.hpp"
#include "ComponentTags.hpp"

#include <entt/entt.hpp>


class InputSystem : public System
{
public:
    InputSystem(entt::registry& registry, entt::dispatcher& dispatcher);

    virtual void update(const Seconds& deltaTime) override;

private:
    InputManager& inputManager;
    entt::entity playerEntity;

    void onPlayerTagAdded(const ComponentParsed<Player>& event);
};