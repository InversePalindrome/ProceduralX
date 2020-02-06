/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - KeyboardManager.cpp
https://inversepalindrome.com/
*/


#include "KeyboardManager.hpp"


void KeyboardManager::update(sf::Window& window)
{
    keyBindings.update(window);
}

bool KeyboardManager::isPressed(Action action) const
{
    return keyBindings.isActive(action);
}