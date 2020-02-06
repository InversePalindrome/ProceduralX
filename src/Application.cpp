/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - Application.cpp
https://inversepalindrome.com/
*/


#include "Application.hpp"

#include <SFML/Window/Event.hpp>


Application::Application() :
    window(sf::VideoMode(2048u, 1536u), "ProceduralX")
{
}

void Application::run()
{
    std::chrono::high_resolution_clock clock;

    auto lastTime = clock.now();

    while (window.isOpen())
    {
        auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(clock.now() - lastTime);

        lastTime = clock.now();

        handleEvents();
        update(deltaTime);
        render();
    }
}

void Application::handleEvents()
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        }
    }
}

void Application::update(const std::chrono::milliseconds& deltaTime)
{

}

void Application::render()
{
    window.clear();

    window.display();
}