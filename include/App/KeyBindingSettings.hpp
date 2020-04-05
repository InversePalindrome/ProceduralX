/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - App/KeyBindingSettings.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/Action.hpp"

#include <Thor/Input/Action.hpp>

#include <unordered_map>


namespace App
{
    struct KeyBinding
    {
        sf::Keyboard::Key key;
        thor::Action::ActionType actionType;
    };

    class KeyBindingSettings
    {
    public:
        static KeyBindingSettings& getInstance();

        void addKeyBinding(Action action, KeyBinding keyBinding);
        void removeKeyBinding(Action action);

    private:
        std::unordered_map<Action, KeyBinding> actionKeyBindingMap;

        KeyBindingSettings() = default;
    };
}