/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - Application.cpp
https://inversepalindrome.com/
*/


#include "Application.hpp"
#include "ResourceManager.hpp"

#include <SFML/Window/Event.hpp>


Application::Application() :
    window(sf::VideoMode(2048u, 1536u), "ProceduralX"),
    stateFactory(window)
{
    loadResources();

    stateMachine.pushState(stateFactory.createState(StateID::Splash));
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

        stateMachine.handleEvent(event);
    }
}

void Application::update(const std::chrono::milliseconds& deltaTime)
{
    keyboardManager.update(window);
    stateMachine.update(deltaTime);
}

void Application::render()
{
    window.clear(sf::Color::White);

    stateMachine.render();

    window.display();
}

void Application::loadResources()
{
    ResourceManager::getInstance().loadTexture(TextureID::SplashLogo, "Resources/Textures/InversePalindromeLogo.png");
}