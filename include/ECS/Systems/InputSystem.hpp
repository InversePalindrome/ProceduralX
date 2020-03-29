/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Systems/InputSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/Action.hpp"
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

        void setActions(thor::ActionMap<Action>* actions);
        void setWindow(sf::RenderWindow* window);

    private:
        thor::ActionMap<Action>* actions;
        sf::RenderWindow* window;

        void updateActions();
        void sendMouseMovedEvent();
        void sendMousePressedEvent();

        sf::Vector2f getMousePosition() const;
    };
}