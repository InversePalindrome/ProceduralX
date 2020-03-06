/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - PlayerSystem.cpp
https://inversepalindrome.com/
*/


#include "PlayerSystem.hpp"
#include "ComponentTags.hpp"
#include "StateComponent.hpp"
#include "PositionConversions.hpp"


PlayerSystem::PlayerSystem(entt::registry& registry, entt::dispatcher& dispatcher) :
    System(registry, dispatcher),
    playerEntity(entt::null)
{
    registry.on_construct<Player>().connect<&PlayerSystem::onPlayerAdded>(this);
    dispatcher.sink<ActionTriggered>().connect<&PlayerSystem::movePlayer>(this);
    dispatcher.sink<MouseMoved>().connect<&PlayerSystem::rotatePlayer>(this);
    dispatcher.sink<MousePressed>().connect<&PlayerSystem::shootProjectile>(this);
}

void PlayerSystem::update(const Seconds& deltaTime)
{

}

void PlayerSystem::onPlayerAdded(entt::entity entity)
{
    playerEntity = entity;
}

void PlayerSystem::movePlayer(const ActionTriggered& event)
{
    switch (event.actionType)
    {
    case InputManager::Action::Up:
        dispatcher.trigger(MoveEntity{ playerEntity, Direction::Up });
        break;
    case InputManager::Action::Down:
        dispatcher.trigger(MoveEntity{ playerEntity, Direction::Down });
        break;
    case InputManager::Action::Right:
        dispatcher.trigger(MoveEntity{ playerEntity, Direction::Right });
        break;
    case InputManager::Action::Left:
        dispatcher.trigger(MoveEntity{ playerEntity, Direction::Left });
        break;
    }
}

void PlayerSystem::rotatePlayer(const MouseMoved& event)
{
    auto worldPosition = Conversions::graphicsToPhysicsPosition(event.position);

    dispatcher.trigger(RotateEntity{ playerEntity, worldPosition });
}

void PlayerSystem::shootProjectile(const MousePressed& event)
{
    auto& state = registry.get<StateComponent>(playerEntity);
    state.setState(EntityState::Shooting);

    dispatcher.trigger(StateChanged{ playerEntity });
}