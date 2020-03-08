/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - InputSystem.cpp
https://inversepalindrome.com/
*/


#include "ECS/Systems/InputSystem.hpp"


ECS::Systems::InputSystem::InputSystem(entt::registry& registry, entt::dispatcher& dispatcher,
    EntityFactory& entityFactory) :
    System(registry, dispatcher, entityFactory),
    window(nullptr)

{
}

void ECS::Systems::InputSystem::update(const App::Seconds& deltaTime)
{
    inputManager.update(*window);
}

void ECS::Systems::InputSystem::handleEvent(const sf::Event& event)
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

void ECS::Systems::InputSystem::setWindow(sf::RenderWindow* window)
{
    this->window = window;
}

void ECS::Systems::InputSystem::sendKeyActionEvent()
{
    if (inputManager.isPressed(App::InputManager::Action::Up))
    {
        dispatcher.trigger(ActionTriggered{ App::InputManager::Action::Up });
    }
    if (inputManager.isPressed(App::InputManager::Action::Down))
    {
        dispatcher.trigger(ActionTriggered{ App::InputManager::Action::Down });
    }
    if (inputManager.isPressed( App::InputManager::Action::Right))
    {
        dispatcher.trigger(ActionTriggered{ App::InputManager::Action::Right });
    }
    if (inputManager.isPressed(App::InputManager::Action::Left))
    {
        dispatcher.trigger(ActionTriggered{ App::InputManager::Action::Left });
    }
}

void ECS::Systems::InputSystem::sendMouseMovedEvent()
{
    dispatcher.trigger(MouseMoved{ getMousePosition() });
}

void ECS::Systems::InputSystem::sendMousePressedEvent()
{
    dispatcher.trigger(MousePressed{ getMousePosition() });
}

sf::Vector2f ECS::Systems::InputSystem::getMousePosition() const
{
    return window->mapPixelToCoords(sf::Mouse::getPosition(*window));
}