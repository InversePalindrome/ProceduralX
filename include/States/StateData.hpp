/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/StateData.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "App/ResourceManager.hpp"
#include "App/AudioSettings.hpp"
#include "App/KeyBindingSettings.hpp"
#include "States/Events/EventDispatcher.hpp"

#include <TGUI/Gui.hpp>

#include <SFML/Graphics/RenderWindow.hpp>


namespace States
{
    struct StateData
    {
        StateData(sf::RenderWindow& window, tgui::Gui& gui, Events::EventDispatcher& eventDispatcher,
            App::ResourceManager& resourceManager, App::AudioSettings& audioSettings,
            App::KeyBindingSettings& keyBindingSettings);

        StateData(const StateData&) = delete;
        StateData& operator=(const StateData&) = delete;
        StateData(StateData&&) = delete;
        StateData& operator=(StateData&&) = delete;

        sf::RenderWindow& window;
        tgui::Gui& gui;

        Events::EventDispatcher& eventDispatcher;

        App::ResourceManager& resourceManager;
        App::AudioSettings& audioSettings;
        App::KeyBindingSettings& keyBindingSettings;
    };
}