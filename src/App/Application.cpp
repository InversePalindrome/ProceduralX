/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - App/Application.cpp
https://inversepalindrome.com/
*/


#include "App/Application.hpp"
#include "App/Constants.hpp"
#include "App/ResourceManager.hpp"
#include "States/StateData.hpp"

#include <SFML/Window/Event.hpp>


using namespace std::chrono_literals;

App::Application::Application() :
    window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), APP_NAME, sf::Style::Titlebar | sf::Style::Close),
    gui(window),
    stateData(window, gui, eventDispatcher, resourceManager, audioSettings, keyBindingSettings),
    stateFactory(stateData)
{
    loadStartupData();

    addEventListeners();

    stateMachine.pushState(stateFactory.createState(States::StateID::Splash));
}

App::Application::~Application()
{
    saveStartupData();
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
        gui.handleEvent(event);
    }
}

void App::Application::update(const Seconds& deltaTime)
{
    stateMachine.update(deltaTime);
}

void App::Application::render()
{
    window.clear(sf::Color::White);

    stateMachine.render();
    gui.draw();

    window.display();
}

void App::Application::loadStartupData()
{
    resourceManager.loadResources("Resources/XML/Resources.xml");
    audioSettings.loadAudioSettings("Settings/AudioSettings.xml");
    keyBindingSettings.loadKeyBindingSettings("Settings/KeyBindingSettings.xml");
}

void App::Application::saveStartupData()
{
    audioSettings.saveAudioSettings("Settings/AudioSettings.xml");
    keyBindingSettings.saveKeyBindingSettings("Settings/KeyBindingSettings.xml");
}

void App::Application::addEventListeners()
{
    eventDispatcher.appendListener(States::Events::EventID::PushState,
        [this](auto stateID)
        {
            stateMachine.pushState(stateFactory.createState(stateID));
        });
    eventDispatcher.appendListener(States::Events::EventID::PopState,
        [this]()
        {
            stateMachine.popState();
        });
    eventDispatcher.appendListener(States::Events::EventID::ChangeState,
        [this](auto stateID)
        {
            stateMachine.popState();
            stateMachine.pushState(stateFactory.createState(stateID));
        });
}