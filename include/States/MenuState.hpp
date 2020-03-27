/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - MenuState.hpp
https://inversepalindrome.com/
*/


#pragma once


#include "States/State.hpp"


namespace States
{
    class MenuState : public State
    {
    public:
        MenuState(sf::RenderWindow& window, tgui::Gui& gui, EventDispatcher& eventDispatcher);

        virtual void handleEvent(const sf::Event& event) override;
        virtual void update(const App::Seconds& deltaTime) override;
        virtual void render() override;

    private:
    };
}