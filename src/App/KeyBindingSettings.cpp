/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - App/KeyBindingSettings.cpp
https://inversepalindrome.com/
*/


#include "App/KeyBindingSettings.hpp"


App::KeyBindingSettings& App::KeyBindingSettings::getInstance()
{
    static KeyBindingSettings instance;

    return instance;
}

void App::KeyBindingSettings::addKeyBinding(Action action, KeyBinding keyBinding)
{
    actionKeyBindingMap[action] = keyBinding;
}

void App::KeyBindingSettings::removeKeyBinding(Action action)
{
    actionKeyBindingMap.erase(action);
}