/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/MenuState.cpp
https://inversepalindrome.com/
*/


#include "States/MenuState.hpp"

#include <TGUI/SignalImpl.hpp>
#include <TGUI/Widgets/Button.hpp>


States::MenuState::MenuState(sf::RenderWindow& window, tgui::Gui& gui, Events::EventDispatcher& eventDispatcher) :
    State(window, gui, eventDispatcher)
{
    auto playButton = tgui::Button::create("Play");
    
    playButton->connect("pressed", [&gui, &eventDispatcher]()
        { 
            eventDispatcher.dispatch(Events::EventID::ChangeState, StateID::Game);
        });

    auto settingsButton = tgui::Button::create("Settings");
    settingsButton->connect("pressed", [&gui, &eventDispatcher]() 
        {
            eventDispatcher.dispatch(Events::EventID::PushState, StateID::Settings);
        });

    auto quitButton = tgui::Button::create("Quit");
    quitButton->connect("pressed", [&window]() { window.close(); });

    menuLayout = tgui::VerticalLayout::create();
    menuLayout->setSize("20%", "20%");
    menuLayout->setPosition("(parent.size - size) / 2");
    menuLayout->add(playButton);
    menuLayout->add(settingsButton);
    menuLayout->add(quitButton);

    gui.add(menuLayout);
}

States::MenuState::~MenuState()
{
    gui.remove(menuLayout);
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

void States::MenuState::onEnter()
{
    menuLayout->setVisible(true);
}

void States::MenuState::onExit()
{
    menuLayout->setVisible(false);
}