/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/SettingsState.cpp
https://inversepalindrome.com/
*/


#include "States/SettingsState.hpp"
#include "App/Constants.hpp"

#include <TGUI/SignalImpl.hpp>
#include <TGUI/Widgets/Label.hpp>
#include <TGUI/Widgets/Slider.hpp>


States::SettingsState::SettingsState(sf::RenderWindow& window, tgui::Gui& gui, Events::EventDispatcher& eventDispatcher) :
    State(window, gui, eventDispatcher)
{
    backButton = tgui::Button::create("Back");
    backButton->setSize("10%", "7%");
    backButton->setTextSize(App::FONT_SIZE);
    backButton->connect("pressed", [&eventDispatcher]() 
        {  
            eventDispatcher.dispatch(Events::EventID::PopState);
        });

    auto soundVolumeLabel = tgui::Label::create("Sound Volume");
    soundVolumeLabel->setTextSize(App::FONT_SIZE);
    soundVolumeLabel->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);
   
    auto soundSlider = tgui::Slider::create();
    soundSlider->connect("ValueChanged", []() {});

    auto musicVolumeLabel = tgui::Label::create("Music Volume");
    musicVolumeLabel->setTextSize(App::FONT_SIZE);
    musicVolumeLabel->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);

    auto musicSlider = tgui::Slider::create();
    musicSlider->connect("ValueChanged", []() {});

    auto moveUpLabel = tgui::Label::create("Move Up");

    auto moveDownLabel = tgui::Label::create("Move Down");

    auto moveRightLabel = tgui::Label::create("Move Right");

    auto moveLeftLabel = tgui::Label::create("Move Left");

    settingsLayout = tgui::VerticalLayout::create();
    settingsLayout->setSize("50%", "50%");
    settingsLayout->setPosition("(parent.size - size) / 2");
    settingsLayout->add(soundVolumeLabel);
    settingsLayout->add(soundSlider);
    settingsLayout->add(musicVolumeLabel);
    settingsLayout->add(musicSlider);

    gui.add(backButton);
    gui.add(settingsLayout);
}

States::SettingsState::~SettingsState()
{
    gui.remove(backButton);
}

void States::SettingsState::handleEvent(const sf::Event& event)
{

}

void States::SettingsState::update(const App::Seconds& deltaTime)
{

}

void States::SettingsState::render()
{

}

void States::SettingsState::onEnter()
{
    backButton->setVisible(true);
    settingsLayout->setVisible(true);
}

void States::SettingsState::onExit()
{
    backButton->setVisible(false);
    settingsLayout->setVisible(false);
}