/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - StateMachine.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "State.hpp"

#include <stack>
#include <memory>


class StateMachine
{
    using StatePtr = std::unique_ptr<State>;

public:
    void pushState(StatePtr state);
    void popState();

    void handleEvent(const sf::Event& event);
    void update(const std::chrono::nanoseconds& deltaTime);
    void render();

    bool isEmpty() const;

private:
    std::stack<StatePtr> states;
};