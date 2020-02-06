/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - Application.hpp
https://inversepalindrome.com/
*/


#pragma once

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

    void handleEvents();
    void update(const std::chrono::milliseconds& deltaTime);
    void render();
};