/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/MenuState.cpp
https://inversepalindrome.com/
*/


#include "States/MenuState.hpp"
#include "States/Events/ChangeStateEvent.hpp"

#include <TGUI/SignalImpl.hpp>
#include <TGUI/Widgets/Button.hpp>
#include <TGUI/Widgets/VerticalLayout.hpp>


States::MenuState::MenuState(sf::RenderWindow& window, tgui::Gui& gui, Events::EventDispatcher& eventDispatcher) :
    State(window, gui, eventDispatcher)
{
    auto playButton = tgui::Button::create("Play");
    
    playButton->connect("pressed", [&gui, &eventDispatcher]()
        { 
            eventDispatcher.dispatch(Events::ChangeStateEvent
            (Events::EventID::ChangeState, StateID::Game));
        });

    auto settingsButton = tgui::Button::create("Settings");
    settingsButton->connect("pressed", [&gui, &eventDispatcher]() 
        {
            eventDispatcher.dispatch(Events::ChangeStateEvent
            (Events::EventID::ChangeState, StateID::Settings));
        });

    auto quitButton = tgui::Button::create("Quit");
    quitButton->connect("pressed", [&window]() { window.close(); });

    auto layout = tgui::VerticalLayout::create();
    layout->setSize("20%", "20%");
    layout->setPosition("(parent.size - size) / 2");
    layout->add(playButton);
    layout->add(settingsButton);
    layout->add(quitButton);

    gui.add(layout);
}

void States::MenuState::handleEvent(const sf::Event& event)
{

}

void States::MenuState::update(const App::Seconds& deltaTime)
{

}

void States::MenuState::render()
{

}