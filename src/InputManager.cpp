/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - InputManager.cpp
https://inversepalindrome.com/
*/


#include "InputManager.hpp"


InputManager::InputManager()
{
    keyBindings[Action::Up] = thor::Action(sf::Keyboard::W, thor::Action::Hold);
    keyBindings[Action::Down] = thor::Action(sf::Keyboard::S, thor::Action::Hold);
    keyBindings[Action::Right] = thor::Action(sf::Keyboard::A, thor::Action::Hold);
    keyBindings[Action::Left] = thor::Action(sf::Keyboard::D, thor::Action::Hold);
}

void InputManager::update(sf::Window& window)
{
    keyBindings.update(window);
}

bool InputManager::isPressed(Action action) const
{
    return keyBindings.isActive(action);
}