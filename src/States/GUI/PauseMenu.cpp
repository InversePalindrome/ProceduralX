/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/GUI/PauseMenu.cpp
https://inversepalindrome.com/
*/


#include "States/GUI/PauseMenu.hpp"

#include <TGUI/SignalImpl.hpp>
#include <TGUI/Widgets/Button.hpp>


States::GUI::PauseMenu::PauseMenu(tgui::Gui& gui, Events::EventDispatcher& eventDispatcher)
{
    auto resumeButton = tgui::Button::create("Resume");
    resumeButton->connect("pressed", []() {});

    auto settingsButton = tgui::Button::create("Settings");
    settingsButton->connect("pressed", []() {});

    auto quitButton = tgui::Button::create("Quit");
    quitButton->connect("pressed", []() {});

    add(resumeButton);
    add(settingsButton);
    add(quitButton);
}