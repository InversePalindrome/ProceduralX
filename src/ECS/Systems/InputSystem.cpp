/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Systems/InputSystem.cpp
https://inversepalindrome.com/
*/


#include "ECS/Systems/Events.hpp"
#include "ECS/Systems/InputSystem.hpp"


ECS::Systems::InputSystem::InputSystem(entt::registry& registry, entt::dispatcher& dispatcher,
    EntityFactory& entityFactory) :
    System(registry, dispatcher, entityFactory),
    actions(nullptr),
    window(nullptr)

{
}

void ECS::Systems::InputSystem::update(const App::Seconds& deltaTime)
{
    updateActions();
}

void ECS::Systems::InputSystem::handleEvent(const sf::Event& event)
{
    switch (event.type)
    {
    case sf::Event::MouseMoved:
        sendMouseMovedEvent();
        break;
    case sf::Event::MouseButtonPressed:
        sendMousePressedEvent();
        break;
    }
}

void ECS::Systems::InputSystem::setActions(thor::ActionMap<Action>* actions)
{
    this->actions = actions;
}

void ECS::Systems::InputSystem::setWindow(sf::RenderWindow* window)
{
    this->window = window;
}

void ECS::Systems::InputSystem::updateActions()
{
    if (actions->isActive(Action::MoveUp))
    {
        dispatcher.trigger(ActionTriggered{ Action::MoveUp });
    }
    if (actions->isActive(Action::MoveDown))
    {
        dispatcher.trigger(ActionTriggered{ Action::MoveDown });
    }
    if (actions->isActive( Action::MoveRight))
    {
        dispatcher.trigger(ActionTriggered{ Action::MoveRight });
    }
    if (actions->isActive(Action::MoveLeft))
    {
        dispatcher.trigger(ActionTriggered{ Action::MoveLeft });
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