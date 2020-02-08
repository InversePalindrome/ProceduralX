/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - State.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "EventDispatcher.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <chrono>


class State
{
public:
    State(sf::RenderWindow& window, EventDispatcher& eventDispatcher);
    virtual ~State() = default;

    virtual void handleEvent(const sf::Event& event) = 0;
    virtual void update(const std::chrono::nanoseconds& deltaTime) = 0;
    virtual void render() = 0;

protected:
    sf::RenderWindow& window;
    EventDispatcher& eventDispatcher;
};