/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - RenderSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "System.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


class RenderSystem : public System
{
public:
    explicit RenderSystem(entt::registry& registry);

    virtual void update(const Seconds& deltaTime) override;

    void setWindow(sf::RenderWindow* window);

private:
    sf::RenderWindow* window;
};