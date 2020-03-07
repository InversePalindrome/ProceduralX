/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - AudioSystem.cpp
https://inversepalindrome.com/
*/


#include "ECS/Systems/AudioSystem.hpp"
#include "ECS/Components/SoundComponent.hpp"


ECS::Systems::AudioSystem::AudioSystem(entt::registry& registry, entt::dispatcher& dispatcher) :
    System(registry, dispatcher)
{
    dispatcher.sink<StateChanged>().connect<&AudioSystem::onStateChanged>(this);
}

void ECS::Systems::AudioSystem::update(const App::Seconds& deltaTime)
{

}

void ECS::Systems::AudioSystem::onStateChanged(const StateChanged& event)
{
    auto entity = event.entity;
    auto state = event.state;
    
    if (registry.has<Components::SoundComponent>(entity))
    {
        auto& sound = registry.get<Components::SoundComponent>(entity);
    
        if (sound.hasSound(state))
        {
            sound.playSound(state);
        }
    }
}