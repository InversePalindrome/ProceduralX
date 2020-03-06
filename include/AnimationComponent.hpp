/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - AnimationComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "AnimationID.hpp"
#include "EntityState.hpp"

#include <Thor/Animations/Animator.hpp>

#include <SFML/Graphics/Sprite.hpp>

#include <unordered_map>


class AnimationComponent
{
public:
    void update(const sf::Time& deltaTime);
    void animate(sf::Sprite& sprite);

    void playAnimation(AnimationID animationID, bool loop = true);
    void stopAnimation();

    void addAnimation(AnimationID animationID, const std::function<void(sf::Sprite&, float)>& animation,
        const sf::Time& duration);

    bool isPlayingAnimation() const;

private:
    thor::Animator<sf::Sprite, AnimationID> animator;
    std::unordered_map<EntityState, AnimationID> stateMap;
};