/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - Application.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "EventID.hpp"
#include "StateMachine.hpp"
#include "StateFactory.hpp"
#include "KeyboardManager.hpp"
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
    KeyboardManager keyboardManager;
    StateFactory stateFactory;
    StateMachine stateMachine;
    EventDispatcher eventDispatcher;

    void handleEvents();
    void update(const std::chrono::nanoseconds& deltaTime);
    void render();

    void addEventListeners();
};