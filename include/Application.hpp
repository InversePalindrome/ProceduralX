/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - Application.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "StateMachine.hpp"
#include "StateFactory.hpp"
#include "KeyboardManager.hpp"

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

    void handleEvents();
    void update(const std::chrono::milliseconds& deltaTime);
    void render();
};