/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - StateFactory.cpp
https://inversepalindrome.com/
*/


#include "MenuState.hpp"
#include "GameState.hpp"
#include "SplashState.hpp"
#include "StateFactory.hpp"


StateFactory::StateFactory(sf::RenderWindow& window, EventDispatcher& eventDispatcher) :
    window(window),
    eventDispatcher(eventDispatcher)
{
    registerState<SplashState>(StateID::Splash);
    registerState<MenuState>(StateID::Menu);
    registerState<GameState>(StateID::Game);
}

StateFactory::StatePtr StateFactory::createState(StateID stateID)
{
    return factory.find(stateID)->second();
}