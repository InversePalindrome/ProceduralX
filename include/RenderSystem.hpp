/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - RenderSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "System.hpp"
#include "SpriteContainer.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


class RenderSystem : public System
{
public:
    RenderSystem(entt::registry& registry, entt::dispatcher& dispatcher);

    virtual void update(const Seconds& deltaTime) override;

    void render();

    void setWindow(sf::RenderWindow* window);

private:
    sf::RenderWindow* window;
    SpriteContainer sprites;
};