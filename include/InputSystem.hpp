/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - InputSystem.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "System.hpp"
#include "Events.hpp"
#include "InputManager.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


class InputSystem : public System
{
public:
    InputSystem(entt::registry& registry, entt::dispatcher& dispatcher);

    virtual void update(const Seconds& deltaTime) override;

    void handleEvent(const sf::Event& event);

    void setWindow(sf::RenderWindow* window);

private:
    InputManager inputManager;
    
    sf::RenderWindow* window;

    void sendKeyActionEvent();
    void sendMouseMovedEvent();
    void sendMousePressedEvent();

    sf::Vector2f getMousePosition() const;
};