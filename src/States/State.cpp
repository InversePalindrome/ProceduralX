/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - State.hpp
https://inversepalindrome.com/
*/


#include "States/State.hpp"


States::State::State(sf::RenderWindow& window, tgui::Gui& gui, EventDispatcher& eventDispatcher) :
    window(window),
    gui(gui),
    eventDispatcher(eventDispatcher)
{
}