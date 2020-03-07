/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - StateMachine.cpp
https://inversepalindrome.com/
*/


#include "States/StateMachine.hpp"


void States::StateMachine::pushState(StatePtr state)
{
    states.push(std::move(state));
}

void States::StateMachine::popState()
{
    states.pop();
}

void States::StateMachine::handleEvent(const sf::Event& event)
{
    states.top()->handleEvent(event);
}

void States::StateMachine::update(const App::Seconds& deltaTime)
{
    states.top()->update(deltaTime);
}

void States::StateMachine::render()
{
    states.top()->render();
}

bool States::StateMachine::isEmpty() const
{
    return states.empty();
}