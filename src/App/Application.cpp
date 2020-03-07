/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - Application.cpp
https://inversepalindrome.com/
*/


#include "App/Application.hpp"
#include "App/Constants.hpp"
#include "App/ResourceManager.hpp"
#include "States/ChangeStateEvent.hpp"

#include <SFML/Window/Event.hpp>

#include <imgui-SFML.h>


using namespace std::chrono_literals;

App::Application::Application() :
    window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
        APP_NAME, sf::Style::Titlebar | sf::Style::Close),
    stateFactory(window, eventDispatcher)
{
    ResourceManager::getInstance().loadResources("Resources/XML/Resources.xml");
    ImGui::SFML::Init(window);

    addEventListeners();

    stateMachine.pushState(stateFactory.createState(States::StateID::Splash));
}

void App::Application::run()
{
    std::chrono::high_resolution_clock clock;
    Seconds elapsedTime(0ms);

    auto startTime = clock.now();

    while (window.isOpen())
    {
        auto deltaTime = clock.now() - startTime;

        startTime = clock.now();
        elapsedTime += deltaTime;

        while (elapsedTime >= TIME_PER_FRAME)
        {
            handleEvents();
            update(TIME_PER_FRAME);
            render();

            elapsedTime -= TIME_PER_FRAME;
        }
    }

    ImGui::SFML::Shutdown();
}

void App::Application::handleEvents()
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

void App::Application::update(const Seconds& deltaTime)
{
    stateMachine.update(deltaTime);
    ImGui::SFML::Update(window, sf::seconds(deltaTime.count()));
}

void App::Application::render()
{
    window.clear(sf::Color::White);

    stateMachine.render();
    ImGui::SFML::Render(window);

    window.display();
}

void App::Application::addEventListeners()
{
    eventDispatcher.appendListener(States::EventID::ChangeState, [this](const auto& event)
    {
        const auto& changeStateEvent = dynamic_cast<const States::ChangeStateEvent&>(event);

        stateMachine.popState();
        stateMachine.pushState(stateFactory.createState(changeStateEvent.transitionState));
    });
}