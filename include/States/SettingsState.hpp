/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/SettingsState.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "States/State.hpp"

#include <TGUI/Widgets/Button.hpp>
#include <TGUI/Widgets/VerticalLayout.hpp>

#include <tuple>
#include <vector>


namespace States
{
    class SettingsState : public State
    {
    public:
        explicit SettingsState(StateData& stateData);

        virtual ~SettingsState() override;

        virtual void handleEvent(const sf::Event& event) override;
        virtual void update(const App::Seconds& deltaTime) override;
        virtual void render() override;
        virtual void onEnter() override;
        virtual void onExit() override;

    private:
        tgui::Button::Ptr backButton;
        std::vector<std::tuple<tgui::Button::Ptr, Action, std::string, bool>> keyBindingWidgets;
        tgui::VerticalLayout::Ptr settingsLayout;

        void initializeAudioWidgets();
        void initializeKeyBindingWidgets();
    };
}