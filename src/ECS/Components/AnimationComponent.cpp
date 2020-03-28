/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/AnimationComponent.cpp
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
    animator.playAnimation(state, animationMap[state].loop);
}

void ECS::Components::AnimationComponent::stopAnimation()
{
    animator.stopAnimation();
}

void ECS::Components::AnimationComponent::addAnimation(State state, const std::function<void(sf::Sprite&, float)>& animation, 
    const AnimationData& animationData)
{
    animationMap[state] = animationData;
    animator.addAnimation(state, animation, sf::seconds(animationData.duration.count()));
}

bool ECS::Components::AnimationComponent::isPlayingAnimation() const
{
    return animator.isPlayingAnimation();
}

bool ECS::Components::AnimationComponent::hasAnimation(State state) const
{
    return animationMap.count(state);
}

ECS::Components::AnimationComponent::Iterator ECS::Components::AnimationComponent::begin()
{
    return animationMap.begin();
}

ECS::Components::AnimationComponent::Iterator ECS::Components::AnimationComponent::end()
{
    return animationMap.end();
}

ECS::Components::AnimationComponent::ConstIterator ECS::Components::AnimationComponent::begin() const
{
    return animationMap.cbegin();
}

ECS::Components::AnimationComponent::ConstIterator ECS::Components::AnimationComponent::end() const
{
    return animationMap.cend();
}