/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - AnimationComponent.cpp
https://inversepalindrome.com/
*/


#include "AnimationComponent.hpp"


void AnimationComponent::update(const sf::Time& deltaTime)
{
    animator.update(deltaTime);
}

void AnimationComponent::animate(sf::Sprite& sprite)
{
    animator.animate(sprite);
}

void AnimationComponent::playAnimation(AnimationID animationID, bool loop)
{
    animator.playAnimation(animationID, loop);
}

void AnimationComponent::stopAnimation()
{
    animator.stopAnimation();
}

void AnimationComponent::addAnimation(AnimationID animationID, const std::function<void(sf::Sprite&, float)>& animation, 
    const sf::Time& duration)
{
    animator.addAnimation(animationID, animation, duration);
}

bool AnimationComponent::isPlayingAnimation() const
{
    return animator.isPlayingAnimation();
}