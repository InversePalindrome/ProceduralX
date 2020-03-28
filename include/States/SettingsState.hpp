/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/SettingsState.hpp
https://inversepalindrome.com/
*/


#pragma once


#include "States/State.hpp"


namespace States
{
    class SettingsState : public State
    {
    public:
        SettingsState(sf::RenderWindow& window, tgui::Gui& gui, Events::EventDispatcher& eventDispatcher);

        virtual void handleEvent(const sf::Event& event) override;
        virtual void update(const App::Seconds& deltaTime) override;
        virtual void render() override;

    private:
    };
}