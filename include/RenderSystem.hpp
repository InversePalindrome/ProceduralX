/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - RenderSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "Map.hpp"
#include "System.hpp"
#include "Events.hpp"
#include "SpriteComponent.hpp"

#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class RenderSystem : public System
{
public:
    RenderSystem(entt::registry& registry, entt::dispatcher& dispatcher);

    virtual void update(const Seconds& deltaTime) override;

    void render();

    void setWindow(sf::RenderWindow* window);
    void setMap(const Map* map);

private:
    entt::entity playerEntity;
    sf::View cameraView;

    sf::RenderWindow* window;
    const Map* map;

    void updateViewPosition();

    void onSpriteAdded(entt::entity);
    void onPlayerAdded(entt::entity entity);
};