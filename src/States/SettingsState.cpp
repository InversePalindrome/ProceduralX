/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/SettingsState.cpp
https://inversepalindrome.com/
*/


#include "States/SettingsState.hpp"
#include "App/Constants.hpp"
#include "App/AudioSettings.hpp"
#include "App/KeyBindingSettings.hpp"

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
   
    auto& audioSettings = App::AudioSettings::getInstance();

    auto soundVolumeSlider = tgui::Slider::create();
    soundVolumeSlider->setValue(audioSettings.getSoundVolume());
    soundVolumeSlider->connect("ValueChanged", [&audioSettings, soundVolumeSlider]() 
        { 
            audioSettings.setSoundVolume(soundVolumeSlider->getValue());
        });

    auto musicVolumeLabel = tgui::Label::create("Music Volume");
    musicVolumeLabel->setTextSize(App::FONT_SIZE);
    musicVolumeLabel->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);

    auto musicVolumeSlider = tgui::Slider::create();
    musicVolumeSlider->setValue(audioSettings.getMusicVolume());
    musicVolumeSlider->connect("ValueChanged", [&audioSettings, musicVolumeSlider]()
        {
            audioSettings.setMusicVolume(musicVolumeSlider->getValue());
        });

    moveUpButton = tgui::Button::create("Move Up");
    moveUpButton->setTextSize(App::FONT_SIZE);

    moveDownButton = tgui::Button::create("Move Down");
    moveDownButton->setTextSize(App::FONT_SIZE);

    moveRightButton = tgui::Button::create("Move Right");
    moveRightButton->setTextSize(App::FONT_SIZE);
    
    moveLeftButton = tgui::Button::create("Move Left");
    moveLeftButton->setTextSize(App::FONT_SIZE);

    settingsLayout = tgui::VerticalLayout::create();
    settingsLayout->setSize("50%", "50%");
    settingsLayout->setPosition("(parent.size - size) / 2");
    settingsLayout->add(soundVolumeLabel);
    settingsLayout->add(soundVolumeSlider);
    settingsLayout->add(musicVolumeLabel);
    settingsLayout->add(musicVolumeSlider);
    settingsLayout->add(moveUpButton);
    settingsLayout->add(moveDownButton);
    settingsLayout->add(moveRightButton);
    settingsLayout->add(moveLeftButton);

    gui.add(backButton);
    gui.add(settingsLayout);
}

States::SettingsState::~SettingsState()
{
    gui.remove(backButton);
    gui.remove(settingsLayout);
}

void States::SettingsState::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        auto& keyBindingSettings = App::KeyBindingSettings::getInstance();

        auto mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        
        if (moveUpButton->mouseOnWidget(mousePosition))
        {
      
        }
        else if (moveDownButton->mouseOnWidget(mousePosition))
        {

        }
        else if (moveRightButton->mouseOnWidget(mousePosition))
        {
 
        }
        else if (moveLeftButton->mouseOnWidget(mousePosition))
        {
  
        }
    }
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