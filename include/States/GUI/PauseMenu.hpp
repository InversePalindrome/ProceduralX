/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/GUI/PauseMenu.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "States/Events/EventDispatcher.hpp"

#include <TGUI/Gui.hpp>
#include <TGUI/Widgets/VerticalLayout.hpp>


namespace States::GUI
{
    class PauseMenu : tgui::VerticalLayout
    {
    public:
        explicit PauseMenu(tgui::Gui& gui, Events::EventDispatcher& eventDispatcher);
        PauseMenu(const PauseMenu&) = delete;
        PauseMenu& operator=(const PauseMenu&) = delete;
        PauseMenu(PauseMenu&&) = delete;
        PauseMenu& operator=(PauseMenu&&) = delete;
    };
}