/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/StateMachine.cpp
https://inversepalindrome.com/
*/


#include "States/StateMachine.hpp"


void States::StateMachine::pushState(StatePtr state)
{
    if (!states.empty())
    {
        states.top()->onExit();
    }

    states.push(std::move(state));
    states.top()->onEnter();
}

void States::StateMachine::popState()
{
    states.top()->onExit();
    states.pop();

    if (!states.empty())
    {
        states.top()->onEnter();
    }
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