/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - AnimationComponent.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/AnimationComponent.hpp"


void ECS::Components::AnimationComponent::update(const sf::Time& deltaTime)
{
    animator.update(deltaTime);
}

void ECS::Components::AnimationComponent::animate(sf::Sprite& sprite)
{
    animator.animate(sprite);
}

void ECS::Components::AnimationComponent::playAnimation(State state)
{
    animator.playAnimation(state, states[state]);
}

void ECS::Components::AnimationComponent::stopAnimation()
{
    animator.stopAnimation();
}

void ECS::Components::AnimationComponent::addAnimation(State state, const std::function<void(sf::Sprite&, float)>& animation, 
    const sf::Time& duration, bool loop)
{
    states[state] = loop;
    animator.addAnimation(state, animation, duration);
}

bool ECS::Components::AnimationComponent::isPlayingAnimation() const
{
    return animator.isPlayingAnimation();
}

bool ECS::Components::AnimationComponent::hasAnimation(State state) const
{
    return states.count(state);
}