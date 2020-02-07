/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - StateFactory.cpp
https://inversepalindrome.com/
*/


#include "StateFactory.hpp"

#include "SplashState.hpp"


StateFactory::StateFactory(sf::RenderWindow& window) :
    window(window)
{
    registerState<SplashState>(StateID::Splash);
}

StateFactory::StatePtr StateFactory::createState(StateID stateID)
{
    return factory.find(stateID)->second();
}