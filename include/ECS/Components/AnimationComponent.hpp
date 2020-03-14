/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - AnimationComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/State.hpp"
#include "ECS/AnimationData.hpp"

#include <Thor/Animations/Animator.hpp>

#include <SFML/Graphics/Sprite.hpp>

#include <unordered_map>


namespace ECS::Components
{
    class AnimationComponent
    {
        using AnimationMap = std::unordered_map<State, AnimationData>;
        using Iterator = AnimationMap::iterator;
        using ConstIterator = AnimationMap::const_iterator;

    public:
        void update(const sf::Time& deltaTime);
        void animate(sf::Sprite& sprite);

        void playAnimation(State state);
        void stopAnimation();

        void addAnimation(State state, const std::function<void(sf::Sprite&, float)>& animation,
            const AnimationData& animationData);

        bool isPlayingAnimation() const;
        bool hasAnimation(State state) const;

        Iterator begin();
        Iterator end();

        ConstIterator begin() const;
        ConstIterator end() const;

    private:
        thor::Animator<sf::Sprite, State> animator;
        AnimationMap animationMap;
    };
}