/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SoundComponent.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/SoundComponent.hpp"


void ECS::Components::SoundComponent::playSound(State state)
{
    sounds[state].second.play();
}

void ECS::Components::SoundComponent::stopSound(State state)
{
    sounds[state].second.stop();
}

void ECS::Components::SoundComponent::addSound(State state, App::SoundID soundID, const sf::Sound& sound)
{
    sounds[state] = { soundID,  sound };
}

void ECS::Components::SoundComponent::removeSound(State state)
{
    sounds.erase(state);
}

sf::Sound& ECS::Components::SoundComponent::operator[](State state)
{
    return sounds[state].second;
}

const sf::Sound& ECS::Components::SoundComponent::operator[](State state) const
{
    return sounds.at(state).second;
}

bool ECS::Components::SoundComponent::hasSound(State state) const
{
    return sounds.count(state);
}

ECS::Components::SoundComponent::Iterator ECS::Components::SoundComponent::begin()
{
    return sounds.begin();
}

ECS::Components::SoundComponent::Iterator ECS::Components::SoundComponent::end()
{
    return sounds.end();
}

ECS::Components::SoundComponent::ConstIterator ECS::Components::SoundComponent::begin() const
{
    return sounds.cbegin();
}

ECS::Components::SoundComponent::ConstIterator ECS::Components::SoundComponent::end() const
{
    return sounds.cend();
}