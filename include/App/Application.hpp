/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - App/Application.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "App/Seconds.hpp"
#include "App/ResourceManager.hpp"
#include "App/AudioSettings.hpp"
#include "App/KeyBindingSettings.hpp"
#include "States/StateData.hpp"
#include "States/StateMachine.hpp"
#include "States/StateFactory.hpp"
#include "States/Events/EventDispatcher.hpp"

#include <TGUI/Gui.hpp>

#include <SFML/Graphics/RenderWindow.hpp>

#include <chrono>


namespace App
{
    class Application
    {
    public:
        Application();
        ~Application();

        void run();

    private:
        sf::RenderWindow window;
        tgui::Gui gui;

        ResourceManager resourceManager;

        AudioSettings audioSettings;
        KeyBindingSettings keyBindingSettings;

        States::Events::EventDispatcher eventDispatcher;

        States::StateData stateData;
        States::StateFactory stateFactory;
        States::StateMachine stateMachine;

        void handleEvents();
        void update(const Seconds& deltaTime);
        void render();

        void loadStartupData();
        void saveStartupData();

        void addEventListeners();
    };
}