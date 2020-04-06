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

#include <Thor/Input/InputNames.hpp>


States::SettingsState::SettingsState(StateData& stateData) :
    State(stateData)
{
    backButton = tgui::Button::create("Back");
    backButton->setSize("10%", "7%");
    backButton->setTextSize(App::FONT_SIZE);
    backButton->connect("pressed", [&stateData]() 
        {  
            stateData.eventDispatcher.dispatch(Events::EventID::PopState);
        });

    keyBindingWidgets.push_back({ tgui::Button::create(), Action::MoveUp, "Move Up", false });
    keyBindingWidgets.push_back({ tgui::Button::create(), Action::MoveDown, "Move Down", false });
    keyBindingWidgets.push_back({ tgui::Button::create(), Action::MoveRight, "Move Right", false });
    keyBindingWidgets.push_back({ tgui::Button::create(), Action::MoveLeft, "Move Left", false });
    keyBindingWidgets.push_back({ tgui::Button::create(), Action::Pause, "Pause", false });

    settingsLayout = tgui::VerticalLayout::create();
    settingsLayout->setSize("50%", "50%");
    settingsLayout->setPosition("(parent.size - size) / 2");

    initializeAudioWidgets();
    initializeKeyBindingWidgets();

    stateData.gui.add(backButton);
    stateData.gui.add(settingsLayout);
}

States::SettingsState::~SettingsState()
{
    stateData.gui.remove(backButton);
    stateData.gui.remove(settingsLayout);
}

void States::SettingsState::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        for (const auto& [button, action, label, hover] : keyBindingWidgets)
        {
            if (hover)
            {
                stateData.keyBindingSettings[action].key = event.key.code;

                button->setText(label + " - " + thor::toString(event.key.code));
            }
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

void States::SettingsState::initializeAudioWidgets()
{
    auto soundVolumeLabel = tgui::Label::create("Sound Volume");
    soundVolumeLabel->setTextSize(App::FONT_SIZE);
    soundVolumeLabel->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);

    auto soundVolumeSlider = tgui::Slider::create();
    soundVolumeSlider->setValue(stateData.audioSettings.getSoundVolume());
    soundVolumeSlider->connect("ValueChanged", [this, soundVolumeSlider]()
        {
            stateData.audioSettings.setSoundVolume(soundVolumeSlider->getValue());
        });

    auto musicVolumeLabel = tgui::Label::create("Music Volume");
    musicVolumeLabel->setTextSize(App::FONT_SIZE);
    musicVolumeLabel->setHorizontalAlignment(tgui::Label::HorizontalAlignment::Center);

    auto musicVolumeSlider = tgui::Slider::create();
    musicVolumeSlider->setValue(stateData.audioSettings.getMusicVolume());
    musicVolumeSlider->connect("ValueChanged", [this, musicVolumeSlider]()
        {
            stateData.audioSettings.setMusicVolume(musicVolumeSlider->getValue());
        });

    settingsLayout->add(soundVolumeLabel);
    settingsLayout->add(soundVolumeSlider);
    settingsLayout->add(musicVolumeLabel);
    settingsLayout->add(musicVolumeSlider);
}

void States::SettingsState::initializeKeyBindingWidgets()
{
    for (auto& [button, action, label, isHovered] : keyBindingWidgets)
    {
        button->setText(label + " - " + thor::toString(stateData.keyBindingSettings[action].key));
        button->setTextSize(App::FONT_SIZE);
        button->connect("MouseEntered", [&isHovered]() { isHovered = true; });
        button->connect("MouseLeft", [&isHovered]() { isHovered = false; });

        settingsLayout->add(button);
    }
}