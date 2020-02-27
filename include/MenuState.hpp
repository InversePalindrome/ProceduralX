/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - MenuState.hpp
https://inversepalindrome.com/
*/


#pragma once


#include "State.hpp"


class MenuState : public State
{
public:
    MenuState(sf::RenderWindow& window, EventDispatcher& eventDispatcher);

    virtual void handleEvent(const sf::Event& event) override;
    virtual void update(const Seconds& deltaTime) override;
    virtual void render() override;

private:
};