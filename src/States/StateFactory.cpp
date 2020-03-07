/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - StateFactory.cpp
https://inversepalindrome.com/
*/


#include "States/MenuState.hpp"
#include "States/GameState.hpp"
#include "States/SplashState.hpp"
#include "States/StateFactory.hpp"


States::StateFactory::StateFactory(sf::RenderWindow& window, EventDispatcher& eventDispatcher) :
    window(window),
    eventDispatcher(eventDispatcher)
{
    registerState<SplashState>(StateID::Splash);
    registerState<MenuState>(StateID::Menu);
    registerState<GameState>(StateID::Game);
}

States::StatePtr States::StateFactory::createState(StateID stateID)
{
    return factory.find(stateID)->second();
}