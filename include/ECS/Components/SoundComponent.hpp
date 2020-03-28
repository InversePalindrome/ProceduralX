/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/SoundComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/State.hpp"
#include "App/ResourceID.hpp"

#include <SFML/Audio/Sound.hpp>
#include <SFML/System/Vector3.hpp>

#include <unordered_map>


namespace ECS::Components
{
    class SoundComponent
    {
        using SoundMap = std::unordered_map<State, std::pair<App::SoundID, sf::Sound>>;
        using Iterator = SoundMap::iterator;
        using ConstIterator = SoundMap::const_iterator;

    public:
        void playSound(State state);
        void stopSound(State state);

        void addSound(State state, App::SoundID soundID, const sf::Sound& sound);
        void removeSound(State state);

        sf::Sound& operator[](State state);
        const sf::Sound& operator[](State state) const;

        bool hasSound(State state) const;

        Iterator begin();
        Iterator end();

        ConstIterator begin() const;
        ConstIterator end() const;

    private:
        SoundMap sounds;
    };
}