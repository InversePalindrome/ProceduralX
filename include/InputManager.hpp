/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - InputManager.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <Thor/Input/ActionMap.hpp>

#include <SFML/Window/Window.hpp>


class InputManager
{
public:
    static InputManager& getInstance();

    InputManager(const InputManager&) = delete;
    InputManager(InputManager&&) = delete;
    InputManager& operator=(const InputManager&) = delete;
    InputManager& operator=(InputManager&&) = delete;

    enum class Action{ Up, Down, Left, Right };

    void update(sf::Window& window);

    bool isPressed(Action action) const;

private:
    InputManager() = default;

    thor::ActionMap<Action> keyBindings;
};