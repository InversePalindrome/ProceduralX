/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/MenuState.hpp
https://inversepalindrome.com/
*/


#pragma once


#include "States/State.hpp"

#include <TGUI/Widgets/VerticalLayout.hpp>


namespace States
{
    class MenuState : public State
    {
    public:
        explicit MenuState(StateData& stateData);
        
        virtual ~MenuState() override;

        virtual void handleEvent(const sf::Event& event) override;
        virtual void update(const App::Seconds& deltaTime) override;
        virtual void render() override;
        virtual void onEnter() override;
        virtual void onExit() override;

    private:
        tgui::VerticalLayout::Ptr menuLayout;
    };
}