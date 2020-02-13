/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - Application.cpp
https://inversepalindrome.com/
*/


#include "Application.hpp"
#include "AppConstants.hpp"
#include "ResourceManager.hpp"
#include "ChangeStateEvent.hpp"

#include <SFML/Window/Event.hpp>

#include <imgui-SFML.h>


using namespace std::chrono_literals;

Application::Application() :
    window(sf::VideoMode(AppConstants::WINDOW_WIDTH, AppConstants::WINDOW_HEIGHT), AppConstants::APP_NAME),
    stateFactory(window, eventDispatcher)
{
    ResourceManager::getInstance().loadResources("Resources/XML/Resources.xml");
    ImGui::SFML::Init(window);

    addEventListeners();

    stateMachine.pushState(stateFactory.createState(StateID::Splash));
}

void Application::run()
{
    std::chrono::high_resolution_clock clock;
    std::chrono::nanoseconds elapsedTime(0ms);

    auto startTime = clock.now();

    while (window.isOpen())
    {
        auto deltaTime = clock.now() - startTime;

        startTime = clock.now();
        elapsedTime += deltaTime;

        while (elapsedTime >= AppConstants::TIME_PER_FRAME)
        {
            handleEvents();
            update(AppConstants::TIME_PER_FRAME);
            render();

            elapsedTime -= AppConstants::TIME_PER_FRAME;
        }
    }

    ImGui::SFML::Shutdown();
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
        ImGui::SFML::ProcessEvent(event);
    }
}

void Application::update(const std::chrono::nanoseconds& deltaTime)
{
    keyboardManager.update(window);
    stateMachine.update(deltaTime);
    ImGui::SFML::Update(window, sf::milliseconds(static_cast<sf::Int32>(std::chrono::duration_cast
        <std::chrono::milliseconds>(deltaTime).count())));
}

void Application::render()
{
    window.clear(sf::Color::White);

    stateMachine.render();
    ImGui::SFML::Render(window);

    window.display();
}

void Application::addEventListeners()
{
    eventDispatcher.appendListener(EventID::ChangeState, [this](const auto& event)
    {
        const auto& changeStateEvent = dynamic_cast<const ChangeStateEvent&>(event);

        stateMachine.popState();
        stateMachine.pushState(stateFactory.createState(changeStateEvent.transitionState));
    });
}