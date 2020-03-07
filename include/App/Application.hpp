/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - Application.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "App/Seconds.hpp"
#include "States/StateMachine.hpp"
#include "States/StateFactory.hpp"
#include "States/EventDispatcher.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#include <chrono>


namespace App
{
    class Application
    {
    public:
        Application();

        void run();

    private:
        sf::RenderWindow window;
        States::StateFactory stateFactory;
        States::StateMachine stateMachine;
        States::EventDispatcher eventDispatcher;

        void handleEvents();
        void update(const Seconds& deltaTime);
        void render();

        void addEventListeners();
    };
}