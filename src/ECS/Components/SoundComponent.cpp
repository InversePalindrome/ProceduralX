/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SoundComponent.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/SoundComponent.hpp"


void ECS::Components::SoundComponent::playSound(State state)
{
    sounds[state].play();
}

void ECS::Components::SoundComponent::stopSound(State state)
{
    sounds[state].stop();
}

void ECS::Components::SoundComponent::addSound(State state, const sf::Sound& sound)
{
    sounds[state] = sound;
}

void ECS::Components::SoundComponent::removeSound(State state)
{
    sounds.erase(state);
}

sf::Sound& ECS::Components::SoundComponent::operator[](State state)
{
    return sounds[state];
}

const sf::Sound& ECS::Components::SoundComponent::operator[](State state) const
{
    return sounds.at(state);
}

bool ECS::Components::SoundComponent::hasSound(State state) const
{
    return sounds.count(state);
}