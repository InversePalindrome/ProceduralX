/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - State.hpp
https://inversepalindrome.com/
*/


#include "States/State.hpp"


States::State::State(sf::RenderWindow& window, EventDispatcher& eventDispatcher) :
    window(window),
    eventDispatcher(eventDispatcher)
{
}