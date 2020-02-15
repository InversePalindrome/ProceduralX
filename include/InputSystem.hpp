/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - InputSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "System.hpp"
#include "InputManager.hpp"


class InputSystem : public System
{
public:
    explicit InputSystem(entt::registry& registry);

    virtual void update(const Seconds& deltaTime) override;

private:
    InputManager& inputManager;
};