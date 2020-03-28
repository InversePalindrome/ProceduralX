/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - App/InputManager.cpp
https://inversepalindrome.com/
*/


#include "App/InputManager.hpp"


App::InputManager::InputManager()
{
    keyBindings[Action::Up] = thor::Action(sf::Keyboard::W, thor::Action::Hold);
    keyBindings[Action::Down] = thor::Action(sf::Keyboard::S, thor::Action::Hold);
    keyBindings[Action::Right] = thor::Action(sf::Keyboard::D, thor::Action::Hold);
    keyBindings[Action::Left] = thor::Action(sf::Keyboard::A, thor::Action::Hold);
}

void App::InputManager::update(sf::Window& window)
{
    keyBindings.update(window);
}

bool App::InputManager::isPressed(Action action) const
{
    return keyBindings.isActive(action);
}