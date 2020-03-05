/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - AudioSystem.cpp
https://inversepalindrome.com/
*/


#include "AudioSystem.hpp"
#include "SoundComponent.hpp"


AudioSystem::AudioSystem(entt::registry& registry, entt::dispatcher& dispatcher) :
    System(registry, dispatcher)
{
    dispatcher.sink<StateChanged>().connect<&AudioSystem::onStateChanged>(this);
}

void AudioSystem::update(const Seconds& deltaTime)
{

}

void AudioSystem::onStateChanged(const StateChanged& event)
{

}