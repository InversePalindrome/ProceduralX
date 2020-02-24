/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - RenderSystem.cpp
https://inversepalindrome.com/
*/


#include "RenderSystem.hpp"
#include "SpriteComponent.hpp"
#include "RotationComponent.hpp"
#include "PositionComponent.hpp"
#include "PositionConversions.hpp"


RenderSystem::RenderSystem(entt::registry& registry, entt::dispatcher& dispatcher) :
    System(registry, dispatcher),
    window(nullptr)
{
}

void RenderSystem::update(const Seconds& deltaTime)
{
    registry.view<SpriteComponent, PositionComponent, RotationComponent>().each(
        [this](auto& sprite, const auto& position, const auto& rotation)
        {
            sprite.setPosition(Conversions::physicsToGraphicsPosition(position.getPosition()));
 
            sprite.setRotation(rotation.getAngle());
        });
}

void RenderSystem::render()
{
    registry.view<SpriteComponent>().each([this](const auto& sprite)
        {
            window->draw(sprite);
        });
}

void RenderSystem::setWindow(sf::RenderWindow* window)
{
    this->window = window;
}