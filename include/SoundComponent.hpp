/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SoundComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "EntityState.hpp"

#include <SFML/Audio/Sound.hpp>
#include <SFML/System/Vector3.hpp>

#include <unordered_map>


class SoundComponent
{
public:
    void playSound(EntityState state);
    void stopSound(EntityState state);

    void addSound(EntityState state, const sf::Sound& sound);
    void removeSound(EntityState state);

    sf::Sound& operator[](EntityState state);
    const sf::Sound& operator[](EntityState state) const;

private:
    std::unordered_map<EntityState, sf::Sound> sounds;
};