/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SoundComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/State.hpp"

#include <SFML/Audio/Sound.hpp>
#include <SFML/System/Vector3.hpp>

#include <unordered_map>


namespace ECS::Components
{
    class SoundComponent
    {
    public:
        void playSound(State state);
        void stopSound(State state);

        void addSound(State state, const sf::Sound& sound);
        void removeSound(State state);

        sf::Sound& operator[](State state);
        const sf::Sound& operator[](State state) const;

        bool hasSound(State state) const;

    private:
        std::unordered_map<State, sf::Sound> sounds;
    };
}