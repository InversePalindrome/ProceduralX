/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - App/AudioSettings.cpp
https://inversepalindrome.com/
*/


#include "App/AudioSettings.hpp"

#include <pugixml.hpp>


App::AudioSettings::AudioSettings() :
    soundVolume(100.f),
    musicVolume(100.f)
{
}

void App::AudioSettings::loadAudioSettings(const std::string& filename)
{
    if (pugi::xml_document doc; doc.load_file(filename.c_str()))
    {
        if (const auto audioSettingsNode = doc.child("AudioSettings"))
        {
            if (const auto soundNode = audioSettingsNode.child("Sound"))
            {
                if (const auto volumeAttribute = soundNode.attribute("volume"))
                {
                    setSoundVolume(volumeAttribute.as_float());
                }
            }
            if (const auto musicNode = audioSettingsNode.child("Music"))
            {
                if (const auto volumeAttribute = musicNode.attribute("volume"))
                {
                    setMusicVolume(volumeAttribute.as_float());
                }
            }
        }
    }
}

void App::AudioSettings::saveAudioSettings(const std::string& filename)
{
    pugi::xml_document doc;

    auto declaration = doc.append_child(pugi::node_declaration);
    declaration.append_attribute("version") = "1.0";
    declaration.append_attribute("encoding") = "UTF-8";

    auto audioSettingsNode = doc.append_child("AudioSettings");

    auto soundNode = audioSettingsNode.append_child("Sound");
    soundNode.append_attribute("volume") = getSoundVolume();

    auto musicNode = audioSettingsNode.append_child("Music");
    musicNode.append_attribute("volume") = getMusicVolume();

    doc.save_file(filename.c_str());
}

float App::AudioSettings::getSoundVolume() const
{
    return soundVolume;
}

void App::AudioSettings::setSoundVolume(float soundVolume)
{
    this->soundVolume = soundVolume;
}

float App::AudioSettings::getMusicVolume() const
{
    return musicVolume;
}

void App::AudioSettings::setMusicVolume(float musicVolume)
{
    this->musicVolume = musicVolume;
}