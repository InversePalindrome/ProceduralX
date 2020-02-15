/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - StateMachine.cpp
https://inversepalindrome.com/
*/


#include "StateMachine.hpp"


void StateMachine::pushState(StatePtr state)
{
    states.push(std::move(state));
}

void StateMachine::popState()
{
    states.pop();
}

void StateMachine::handleEvent(const sf::Event& event)
{
    states.top()->handleEvent(event);
}

void StateMachine::update(const Seconds& deltaTime)
{
    states.top()->update(deltaTime);
}

void StateMachine::render()
{
    states.top()->render();
}

bool StateMachine::isEmpty() const
{
    return states.empty();
}