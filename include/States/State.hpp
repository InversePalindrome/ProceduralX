/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/State.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "App/Seconds.hpp"
#include "States/StateData.hpp"

#include <SFML/Window/Event.hpp>


namespace States
{
    class State
    {
    public:
        explicit State(StateData& stateData);
        State(const State&) = delete;
        State& operator=(const State&) = delete;
        State(State&&) = delete;
        State& operator=(State&&) = delete;

        virtual ~State() = default;

        virtual void handleEvent(const sf::Event& event) = 0;
        virtual void update(const App::Seconds& deltaTime) = 0;
        virtual void render() = 0;

        virtual void onEnter() {};
        virtual void onExit() {};

    protected:
        StateData& stateData;
    };
}