/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/SettingsState.hpp
https://inversepalindrome.com/
*/


#pragma once


#include "States/State.hpp"

#include <TGUI/Widgets/Button.hpp>
#include <TGUI/Widgets/VerticalLayout.hpp>


namespace States
{
    class SettingsState : public State
    {
    public:
        SettingsState(sf::RenderWindow& window, tgui::Gui& gui, Events::EventDispatcher& eventDispatcher);

        virtual ~SettingsState() override;

        virtual void handleEvent(const sf::Event& event) override;
        virtual void update(const App::Seconds& deltaTime) override;
        virtual void render() override;
        virtual void onEnter() override;
        virtual void onExit() override;

    private:
        tgui::Button::Ptr backButton;
        tgui::VerticalLayout::Ptr settingsLayout;
    };
}