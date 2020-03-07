/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - InputSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/Systems/System.hpp"
#include "ECS/Systems/Events.hpp"
#include "App/InputManager.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


namespace ECS::Systems
{
    class InputSystem : public System
    {
    public:
        InputSystem(entt::registry& registry, entt::dispatcher& dispatcher);

        virtual void update(const App::Seconds& deltaTime) override;

        void handleEvent(const sf::Event& event);

        void setWindow(sf::RenderWindow* window);

    private:
        App::InputManager inputManager;

        sf::RenderWindow* window;

        void sendKeyActionEvent();
        void sendMouseMovedEvent();
        void sendMousePressedEvent();

        sf::Vector2f getMousePosition() const;
    };
}