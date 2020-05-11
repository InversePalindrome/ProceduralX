/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - App/KeyBindingSettings.cpp
https://inversepalindrome.com/
*/


#include "App/KeyBindingSettings.hpp"

#include <magic_enum.hpp>

#include <pugixml.hpp>


App::KeyBindingSettings::KeyBindingSettings() :
    actionKeyBindingMap
    ({
        {Action::MoveUp, KeyBinding{sf::Keyboard::W, thor::Action::Hold}},
        {Action::MoveDown, KeyBinding{sf::Keyboard::S, thor::Action::Hold}},
        {Action::MoveRight, KeyBinding{sf::Keyboard::D, thor::Action::Hold}},
        {Action::MoveLeft, KeyBinding{sf::Keyboard::A, thor::Action::Hold}},
        {Action::Pause, KeyBinding{sf::Keyboard::Escape, thor::Action::Hold}}
        })
{
}

void App::KeyBindingSettings::loadKeyBindingSettings(const std::string& filename)
{
    if (pugi::xml_document doc; doc.load_file(filename.c_str()))
    {
        if (const auto keyBindingSettingsNode = doc.child("KeyBindingSettings"))
        {
            for (const auto keyBindingNode : keyBindingSettingsNode.children("KeyBinding"))
            {
                if (const auto actionAttribute = keyBindingNode.attribute("action"),
                    keyAttribute = keyBindingNode.attribute("key"),
                    typeAttribute = keyBindingNode.attribute("type");
                    actionAttribute && keyAttribute && typeAttribute)
                {
                    auto actionOptional = magic_enum::enum_cast<Action>(actionAttribute.as_string());
                    auto keyOptional = magic_enum::enum_cast<sf::Keyboard::Key>(keyAttribute.as_string());
                    auto typeOptional = magic_enum::enum_cast<thor::Action::ActionType>(typeAttribute.as_string());

                    if (actionOptional.has_value() && keyOptional.has_value() && typeOptional.has_value())
                    {
                        addKeyBinding(actionOptional.value(), { keyOptional.value(), typeOptional.value() });
                    }
                }
            }
        }
    }
}

void App::KeyBindingSettings::saveKeyBindingSettings(const std::string& filename)
{
    pugi::xml_document doc;

    auto declaration = doc.append_child(pugi::node_declaration);
    declaration.append_attribute("version") = "1.0";
    declaration.append_attribute("encoding") = "UTF-8";

    auto keyBindingSettingsNode = doc.append_child("KeyBindingSettings");

    for (const auto& [action, keyBinding] : actionKeyBindingMap)
    {
        auto keyBindingNode = keyBindingSettingsNode.append_child("KeyBinding");
        keyBindingNode.append_attribute("action") = std::string(magic_enum::enum_name(action)).c_str();
        keyBindingNode.append_attribute("key") = std::string(magic_enum::enum_name(keyBinding.key)).c_str();
        keyBindingNode.append_attribute("type") = std::string(magic_enum::enum_name(keyBinding.actionType)).c_str();
    }

    doc.save_file(filename.c_str());
}

App::KeyBinding& App::KeyBindingSettings::operator[](Action action)
{
    return actionKeyBindingMap[action];
}

const App::KeyBinding& App::KeyBindingSettings::operator[](Action action) const
{
    return actionKeyBindingMap.at(action);
}

void App::KeyBindingSettings::addKeyBinding(Action action, KeyBinding keyBinding)
{
    actionKeyBindingMap[action] = keyBinding;
}

void App::KeyBindingSettings::removeKeyBinding(Action action)
{
    actionKeyBindingMap.erase(action);
}

App::KeyBindingSettings::Iterator App::KeyBindingSettings::begin()
{
    return actionKeyBindingMap.begin();
}

App::KeyBindingSettings::Iterator App::KeyBindingSettings::end()
{
    return actionKeyBindingMap.end();
}

App::KeyBindingSettings::ConstIterator App::KeyBindingSettings::begin() const
{
    return actionKeyBindingMap.begin();
}

App::KeyBindingSettings::ConstIterator App::KeyBindingSettings::end() const
{
    return actionKeyBindingMap.end();
}