/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - App/KeyBindingSettings.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "App/Action.hpp"

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
        using ActionKeyMap = std::unordered_map<Action, KeyBinding>;
        using Iterator = ActionKeyMap::iterator;
        using ConstIterator = ActionKeyMap::const_iterator;

    public:
        KeyBindingSettings();

        void loadKeyBindingSettings(const std::string& filename);
        void saveKeyBindingSettings(const std::string& filename);

        KeyBinding& operator[](Action action);
        const KeyBinding& operator[](Action action) const;

        void addKeyBinding(Action action, KeyBinding keyBinding);
        void removeKeyBinding(Action action);

        Iterator begin();
        Iterator end();

        ConstIterator begin() const;
        ConstIterator end() const;

    private:
        ActionKeyMap actionKeyBindingMap;
    };
}