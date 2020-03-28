/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/SettingsState.cpp
https://inversepalindrome.com/
*/


#include "States/SettingsState.hpp"
#include "States/Events/ChangeStateEvent.hpp"

#include <TGUI/SignalImpl.hpp>
#include <TGUI/Widgets/Button.hpp>


States::SettingsState::SettingsState(sf::RenderWindow& window, tgui::Gui& gui, Events::EventDispatcher& eventDispatcher) :
    State(window, gui, eventDispatcher)
{
    auto backButton = tgui::Button::create("Back");
    backButton->setSize("10%", "10%");
    backButton->connect("pressed", [&eventDispatcher]() 
        {  
            eventDispatcher.dispatch(Events::ChangeStateEvent(Events::EventID::ChangeState, StateID::Menu));
        });

    gui.add(backButton);
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