/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - StateFactory.cpp
https://inversepalindrome.com/
*/


#include "StateFactory.hpp"

#include "SplashState.hpp"
#include "SimulationState.hpp"


StateFactory::StateFactory(sf::RenderWindow& window, EventDispatcher& eventDispatcher) :
    window(window),
    eventDispatcher(eventDispatcher)
{
    registerState<SplashState>(StateID::Splash);
    registerState<SimulationState>(StateID::Simulation);
}

StateFactory::StatePtr StateFactory::createState(StateID stateID)
{
    return factory.find(stateID)->second();
}