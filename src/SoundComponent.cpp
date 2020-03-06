/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SoundComponent.cpp
https://inversepalindrome.com/
*/


#include "SoundComponent.hpp"


void SoundComponent::playSound(EntityState state)
{
    sounds[state].play();
}

void SoundComponent::stopSound(EntityState state)
{
    sounds[state].stop();
}

void SoundComponent::addSound(EntityState state, const sf::Sound& sound)
{
    sounds[state] = sound;
}

void SoundComponent::removeSound(EntityState state)
{
    sounds.erase(state);
}

sf::Sound& SoundComponent::operator[](EntityState state)
{
    return sounds[state];
}

const sf::Sound& SoundComponent::operator[](EntityState state) const
{
    return sounds.at(state);
}

bool SoundComponent::hasSound(EntityState state) const
{
    return sounds.count(state);
}