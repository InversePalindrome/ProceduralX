/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/StateFactory.cpp
https://inversepalindrome.com/
*/


#include "States/MenuState.hpp"
#include "States/GameState.hpp"
#include "States/SplashState.hpp"
#include "States/StateFactory.hpp"
#include "States/SettingsState.hpp"


States::StateFactory::StateFactory(sf::RenderWindow& window, tgui::Gui& gui, Events::EventDispatcher& eventDispatcher) :
    window(window),
    gui(gui),
    eventDispatcher(eventDispatcher)
{
    registerState<SplashState>(StateID::Splash);
    registerState<SettingsState>(StateID::Settings);
    registerState<MenuState>(StateID::Menu);
    registerState<GameState>(StateID::Game);
}

States::StatePtr States::StateFactory::createState(StateID stateID)
{
    return factory.find(stateID)->second();
}