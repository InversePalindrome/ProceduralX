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


States::StateFactory::StateFactory(StateData& stateData) :
    stateData(stateData)
{
    registerState<SplashState>(StateID::Splash);
    registerState<SettingsState>(StateID::Settings);
    registerState<MenuState>(StateID::Menu);
    registerState<GameState>(StateID::Game);
}

States::StateFactory::StatePtr States::StateFactory::createState(StateID stateID)
{
    return factory.find(stateID)->second();
}