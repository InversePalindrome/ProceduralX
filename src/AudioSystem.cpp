/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - AudioSystem.cpp
https://inversepalindrome.com/
*/


#include "AudioSystem.hpp"
#include "SoundComponent.hpp"
#include "StateComponent.hpp"


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
    auto entity = event.entity;

    const auto& stateComponent = registry.get<StateComponent>(entity);
    auto state = stateComponent.getState();
    
    if (registry.has<SoundComponent>(entity))
    {
        auto& sound = registry.get<SoundComponent>(entity);
    
        if (sound.hasSound(state))
        {
            sound.playSound(state);
        }
    }
}