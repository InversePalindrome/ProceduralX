/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/SettingsState.cpp
https://inversepalindrome.com/
*/


#include "States/SettingsState.hpp"

#include <TGUI/SignalImpl.hpp>


States::SettingsState::SettingsState(sf::RenderWindow& window, tgui::Gui& gui, Events::EventDispatcher& eventDispatcher) :
    State(window, gui, eventDispatcher)
{
    backButton = tgui::Button::create("Back");
    backButton->setSize("10%", "10%");
    backButton->connect("pressed", [&eventDispatcher]() 
        {  
            eventDispatcher.dispatch(Events::EventID::PopState);
        });

    gui.add(backButton);
}

States::SettingsState::~SettingsState()
{
    gui.remove(backButton);
}

void States::SettingsState::handleEvent(const sf::Event& event)
{

}

void States::SettingsState::update(const App::Seconds& deltaTime)
{

}

void States::SettingsState::render()
{

}

void States::SettingsState::onEnter()
{
    backButton->setVisible(true);
}

void States::SettingsState::onExit()
{
    backButton->setVisible(false);
}