/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Systems/AudioSystem.cpp
https://inversepalindrome.com/
*/


#include "ECS/Systems/AudioSystem.hpp"
#include "ECS/Components/SoundComponent.hpp"
#include "ECS/Components/TransformComponent.hpp"
#include "ECS/Utility/PositionConversions.hpp"

#include <SFML/Audio/Listener.hpp>


ECS::Systems::AudioSystem::AudioSystem(entt::registry& registry, entt::dispatcher& dispatcher, 
    EntityFactory& entityFactory) :
    System(registry, dispatcher, entityFactory),
    playerEntity(entt::null),
    audioSettings(nullptr)
{
    registry.on_construct<entt::tag<"Player"_hs>>().connect<&AudioSystem::onPlayerAdded>(this);
    dispatcher.sink<StateChanged>().connect<&AudioSystem::onStateChanged>(this);
}

void ECS::Systems::AudioSystem::update(const App::Seconds& deltaTime)
{
    updateListenerPosition();
}

void ECS::Systems::AudioSystem::setAudioSettings(const App::AudioSettings* audioSettings)
{
    this->audioSettings = audioSettings;
}

void ECS::Systems::AudioSystem::onPlayerAdded(entt::entity entity)
{
    this->playerEntity = entity;
}

void ECS::Systems::AudioSystem::onStateChanged(const StateChanged& event)
{
    auto entity = event.entity;
    auto state = event.state;
    
    if (registry.has<Components::SoundComponent>(entity))
    {
        auto& soundComponent = registry.get<Components::SoundComponent>(entity);
    
        if (soundComponent.hasSound(state))
        {
            auto& sound = soundComponent[state];
            sound.setVolume(audioSettings->getSoundVolume());
            sound.play();

            if (registry.has<Components::TransformComponent>(entity))
            {
                const auto& transform = registry.get<Components::TransformComponent>(entity);

                auto sourcePosition = Utility::physicsToGraphicsPosition(transform.getPosition());

                sound.setPosition({ sourcePosition.x, 0.f, sourcePosition.y });
            }
        }
    }
}

void ECS::Systems::AudioSystem::updateListenerPosition()
{
    if (registry.has<Components::TransformComponent>(playerEntity))
    {
        const auto& transform = registry.get<Components::TransformComponent>(playerEntity);

        auto listenerPosition = Utility::physicsToGraphicsPosition(transform.getPosition());

        sf::Listener::setPosition({ listenerPosition.x, 0.f, listenerPosition.y });
    }
}