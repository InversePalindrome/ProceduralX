/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - Application.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "EventID.hpp"
#include "Seconds.hpp"
#include "StateMachine.hpp"
#include "StateFactory.hpp"
#include "EventDispatcher.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#include <chrono>


class Application
{
public:
    Application();

    void run();

private:
    sf::RenderWindow window;
    StateFactory stateFactory;
    StateMachine stateMachine;
    EventDispatcher eventDispatcher;

    void handleEvents();
    void update(const Seconds& deltaTime);
    void render();

    void addEventListeners();
};