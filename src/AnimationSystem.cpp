/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - AnimationSystem.cpp
https://inversepalindrome.com/
*/


#include "AnimationSystem.hpp"
#include "SpriteComponent.hpp"
#include "AnimationComponent.hpp"


AnimationSystem::AnimationSystem(entt::registry& registry, entt::dispatcher& dispatcher) :
    System(registry, dispatcher)
{
}

void AnimationSystem::update(const Seconds& deltaTime)
{
    registry.view<AnimationComponent, SpriteComponent>().each(
        [deltaTime](auto& animation, auto& sprite)
        {
            animation.update(sf::seconds(deltaTime.count()));
            animation.animate(sprite.getSprite());
        });
}