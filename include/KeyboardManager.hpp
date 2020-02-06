/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - KeyboardManager.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <Thor/Input/ActionMap.hpp>

#include <SFML/Window/Window.hpp>


class KeyboardManager
{
public:
    enum class Action{ Up, Down, Left, Right };

    void update(sf::Window& window);

    bool isPressed(Action action) const;

private:
    thor::ActionMap<Action> keyBindings;
};