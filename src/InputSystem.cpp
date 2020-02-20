/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - InputSystem.cpp
https://inversepalindrome.com/
*/


#include "InputSystem.hpp"


InputSystem::InputSystem(entt::registry& registry, entt::dispatcher& dispatcher) :
    System(registry, dispatcher),
    inputManager(InputManager::getInstance())
{
    dispatcher.sink<ComponentParsed<Player>>().connect<&InputSystem::onPlayerTagAdded>(this);
}

void InputSystem::update(const Seconds& deltaTime)
{
    if (registry.valid(playerEntity))
    {

    }
}

void InputSystem::onPlayerTagAdded(const ComponentParsed<Player>& event)
{
    
}