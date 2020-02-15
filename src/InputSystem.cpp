/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - InputSystem.cpp
https://inversepalindrome.com/
*/


#include "InputSystem.hpp"


InputSystem::InputSystem(entt::registry& registry) :
    System(registry),
    inputManager(InputManager::getInstance())
{
}

void InputSystem::update(const Seconds& deltaTime)
{
    
}