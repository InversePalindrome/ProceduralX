/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - AnimationSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "System.hpp"
#include "Events.hpp"


class AnimationSystem : public System
{
public:
    AnimationSystem(entt::registry& registry, entt::dispatcher& dispatcher);

    virtual void update(const Seconds& deltaTime) override;

private:
    void onStateChanged(const StateChanged& event);
};