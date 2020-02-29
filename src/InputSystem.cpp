/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - InputSystem.cpp
https://inversepalindrome.com/
*/


#include "InputSystem.hpp"
#include "ComponentTags.hpp"
#include "PositionConversions.hpp"


InputSystem::InputSystem(entt::registry& registry, entt::dispatcher& dispatcher) :
    System(registry, dispatcher),
    playerEntity(entt::null),
    window(nullptr)

{
    registry.on_construct<Player>().connect<&InputSystem::onPlayerTagAdded>(this);
}

void InputSystem::update(const Seconds& deltaTime)
{
    inputManager.update(*window);

    if (registry.valid(playerEntity))
    {
        sendKeyPressedEvents();
        sendMouseEvents();
    }
}

void InputSystem::setWindow(sf::Window* window)
{
    this->window = window;
}

void InputSystem::onPlayerTagAdded(entt::entity entity)
{
    playerEntity = entity;
}

void InputSystem::sendKeyPressedEvents()
{
    if (inputManager.isPressed(InputManager::Action::Up))
    {
        dispatcher.trigger(MoveEntity{ playerEntity, Direction::Up });
    }
    if (inputManager.isPressed(InputManager::Action::Down))
    {
        dispatcher.trigger(MoveEntity{ playerEntity, Direction::Down });
    }
    if (inputManager.isPressed(InputManager::Action::Right))
    {
        dispatcher.trigger(MoveEntity{ playerEntity, Direction::Right });
    }
    if (inputManager.isPressed(InputManager::Action::Left))
    {
        dispatcher.trigger(MoveEntity{ playerEntity, Direction::Left });
    }
}

void InputSystem::sendMouseEvents()
{
    const auto mousePosition = sf::Mouse::getPosition(*window);

    dispatcher.trigger(RotateEntity{ playerEntity, Conversions::graphicsToPhysicsPosition
    ({static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y) }) });
}