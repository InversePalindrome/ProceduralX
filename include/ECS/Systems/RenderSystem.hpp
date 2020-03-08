/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - RenderSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/Map.hpp"
#include "ECS/Systems/System.hpp"
#include "ECS/Systems/Events.hpp"
#include "ECS/Components/SpriteComponent.hpp"

#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


namespace ECS::Systems
{
    class RenderSystem : public System
    {
    public:
        RenderSystem(entt::registry& registry, entt::dispatcher& dispatcher, EntityFactory& entityFactory);

        virtual void update(const App::Seconds& deltaTime) override;

        void render();

        void setWindow(sf::RenderWindow* window);

    private:
        entt::entity playerEntity;
        sf::View cameraView;

        sf::RenderWindow* window;
        Map map;

        void updateViewPosition();

        void onSpriteAdded(entt::entity);
        void onPlayerAdded(entt::entity entity);
    };
}