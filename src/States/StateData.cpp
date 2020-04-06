/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/StateData.cpp
https://inversepalindrome.com/
*/


#include "States/StateData.hpp"


States::StateData::StateData(sf::RenderWindow& window, tgui::Gui& gui, Events::EventDispatcher& eventDispatcher,
    App::ResourceManager& resourceManager, App::AudioSettings& audioSettings, App::KeyBindingSettings& keyBindingSettings) :
    window(window),
    gui(gui),
    eventDispatcher(eventDispatcher),
    resourceManager(resourceManager),
    audioSettings(audioSettings),
    keyBindingSettings(keyBindingSettings)
{
}