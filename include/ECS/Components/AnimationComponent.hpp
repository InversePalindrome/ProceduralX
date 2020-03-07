/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - AnimationComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/State.hpp"

#include <Thor/Animations/Animator.hpp>

#include <SFML/Graphics/Sprite.hpp>

#include <unordered_map>


namespace ECS::Components
{
    class AnimationComponent
    {
    public:
        void update(const sf::Time& deltaTime);
        void animate(sf::Sprite& sprite);

        void playAnimation(State state);
        void stopAnimation();

        void addAnimation(State state, const std::function<void(sf::Sprite&, float)>& animation,
            const sf::Time& duration, bool loop = false);

        bool isPlayingAnimation() const;
        bool hasAnimation(State state) const;

    private:
        thor::Animator<sf::Sprite, State> animator;
        std::unordered_map<State, bool> states;
    };
}