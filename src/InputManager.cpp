/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - InputManager.cpp
https://inversepalindrome.com/
*/


#include "InputManager.hpp"


InputManager& InputManager::getInstance()
{
    static InputManager instance;

    return instance;
}

void InputManager::update(sf::Window& window)
{
    keyBindings.update(window);
}

bool InputManager::isPressed(Action action) const
{
    return keyBindings.isActive(action);
}