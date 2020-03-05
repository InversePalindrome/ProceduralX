/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - InputSystem.cpp
https://inversepalindrome.com/
*/


#include "InputSystem.hpp"


InputSystem::InputSystem(entt::registry& registry, entt::dispatcher& dispatcher) :
    System(registry, dispatcher),
    window(nullptr)

{
}

void InputSystem::update(const Seconds& deltaTime)
{
    inputManager.update(*window);
}

void InputSystem::handleEvent(const sf::Event& event)
{
    switch (event.type)
    {
    case sf::Event::KeyPressed:
        sendKeyActionEvent();
        break;
    case sf::Event::MouseMoved:
        sendMouseMovedEvent();
        break;
    case sf::Event::MouseButtonPressed:
        sendMousePressedEvent();
        break;
    }
}

void InputSystem::setWindow(sf::RenderWindow* window)
{
    this->window = window;
}

void InputSystem::sendKeyActionEvent()
{
    if (inputManager.isPressed(InputManager::Action::Up))
    {
        dispatcher.trigger(ActionTriggered{ InputManager::Action::Up });
    }
    if (inputManager.isPressed(InputManager::Action::Down))
    {
        dispatcher.trigger(ActionTriggered{ InputManager::Action::Down });
    }
    if (inputManager.isPressed(InputManager::Action::Right))
    {
        dispatcher.trigger(ActionTriggered{ InputManager::Action::Right });
    }
    if (inputManager.isPressed(InputManager::Action::Left))
    {
        dispatcher.trigger(ActionTriggered{ InputManager::Action::Left });
    }
}

void InputSystem::sendMouseMovedEvent()
{
    dispatcher.trigger(MouseMoved{ getMousePosition() });
}

void InputSystem::sendMousePressedEvent()
{
    dispatcher.trigger(MousePressed{ getMousePosition() });
}

sf::Vector2f InputSystem::getMousePosition() const
{
    return window->mapPixelToCoords(sf::Mouse::getPosition(*window));
}