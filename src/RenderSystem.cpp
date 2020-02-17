/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - RenderSystem.cpp
https://inversepalindrome.com/
*/


#include "RenderSystem.hpp"
#include "SpriteComponent.hpp"


RenderSystem::RenderSystem(entt::registry& registry, entt::dispatcher& dispatcher) :
    System(registry, dispatcher),
    window(nullptr)
{
}

void RenderSystem::update(const Seconds& deltaTime)
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