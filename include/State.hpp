/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - State.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <chrono>


class State
{
public:
    explicit State(sf::RenderWindow& window);

    virtual void handleEvent(const sf::Event& event) = 0;
    virtual void update(const std::chrono::milliseconds& deltaTime) = 0;
    virtual void render() = 0;

protected:
    sf::RenderWindow& window;
};