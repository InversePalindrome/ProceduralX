/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - AnimationSystem.cpp
https://inversepalindrome.com/
*/


#include "ECS/Systems/AnimationSystem.hpp"
#include "ECS/Components/SpriteComponent.hpp"
#include "ECS/Components/AnimationComponent.hpp"


ECS::Systems::AnimationSystem::AnimationSystem(entt::registry& registry, entt::dispatcher& dispatcher, 
    EntityFactory& entityFactory) :
    System(registry, dispatcher, entityFactory)
{
    dispatcher.sink<StateChanged>().connect<&AnimationSystem::onStateChanged>(this);
}

void ECS::Systems::AnimationSystem::update(const App::Seconds& deltaTime)
{
    registry.view<Components::AnimationComponent, Components::SpriteComponent>().each(
        [deltaTime](auto& animation, auto& sprite)
        {
            animation.update(sf::seconds(deltaTime.count()));
            animation.animate(sprite.getSprite());
        });
}

void ECS::Systems::AnimationSystem::onStateChanged(const StateChanged& event)
{
    auto entity = event.entity;
    auto state = event.state;

    if (registry.has<Components::AnimationComponent>(entity))
    {
        auto& animation = registry.get<Components::AnimationComponent>(entity);

        if (animation.hasAnimation(state))
        {
            animation.playAnimation(state);
        }
    }
}