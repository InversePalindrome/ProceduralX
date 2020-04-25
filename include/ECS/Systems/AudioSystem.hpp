/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Systems/AudioSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/Systems/System.hpp"
#include "ECS/Systems/Events.hpp"
#include "App/AudioSettings.hpp"


namespace ECS::Systems
{
    class AudioSystem : public System
    {
    public:
        AudioSystem(entt::registry& registry, entt::dispatcher& dispatcher, EntityFactory& entityFactory);

        virtual void update(const App::Seconds& deltaTime) override;

        void setAudioSettings(const App::AudioSettings* audioSettings);

    private:
        entt::entity playerEntity;
        const App::AudioSettings* audioSettings;

        void onPlayerAdded(entt::registry&, entt::entity entity);
        void onStateChanged(const StateChanged& event);

        void updateListenerPosition();
    };
}