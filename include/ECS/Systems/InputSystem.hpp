/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Systems/InputSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "App/Action.hpp"
#include "ECS/Systems/System.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#include <Thor/Input/ActionMap.hpp>


namespace ECS::Systems
{
    class InputSystem : public System
    {
    public:
        InputSystem(entt::registry& registry, entt::dispatcher& dispatcher, EntityFactory& entityFactory);

        virtual void update(const App::Seconds& deltaTime) override;

        void handleEvent(const sf::Event& event);

        void setActions(thor::ActionMap<App::Action>* actions);
        void setWindow(sf::RenderWindow* window);

    private:
        sf::Vector2f mousePosition;

        thor::ActionMap<App::Action>* actions;
        sf::RenderWindow* window;

        void updateActions();
        void updateMousePosition(const sf::Vector2i& mousePosition);
        void sendMouseMovedEvent();
        void sendMousePressedEvent();
    };
}