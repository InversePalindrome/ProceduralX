/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - AudioSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "System.hpp"
#include "Events.hpp"


class AudioSystem : public System
{
public:
    AudioSystem(entt::registry& registry, entt::dispatcher& dispatcher);

    virtual void update(const Seconds& deltaTime) override;

private:
    void onStateChanged(const StateChanged& event);
};