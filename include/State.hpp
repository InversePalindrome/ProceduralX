/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - State.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "Seconds.hpp"
#include "EventDispatcher.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class State
{
public:
    State(sf::RenderWindow& window, EventDispatcher& eventDispatcher);
    State(const State&) = delete;
    State& operator=(const State&) = delete;
    State(State&&) = default;
    State& operator=(State&&) = default;

    virtual ~State() = default;

    virtual void handleEvent(const sf::Event& event) = 0;
    virtual void update(const Seconds& deltaTime) = 0;
    virtual void render() = 0;

protected:
    sf::RenderWindow& window;
    EventDispatcher& eventDispatcher;
};