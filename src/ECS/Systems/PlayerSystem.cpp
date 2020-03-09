/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - PlayerSystem.cpp
https://inversepalindrome.com/
*/


#include "ECS/Systems/PlayerSystem.hpp"
#include "ECS/Components/ComponentTags.hpp"
#include "ECS/Utility/PositionConversions.hpp"


ECS::Systems::PlayerSystem::PlayerSystem(entt::registry& registry, entt::dispatcher& dispatcher,
    EntityFactory& entityFactory) :
    System(registry, dispatcher, entityFactory),
    playerEntity(entt::null)
{
    registry.on_construct<Components::Player>().connect<&PlayerSystem::onPlayerAdded>(this);
    dispatcher.sink<ActionTriggered>().connect<&PlayerSystem::movePlayer>(this);
    dispatcher.sink<MouseMoved>().connect<&PlayerSystem::rotatePlayer>(this);
    dispatcher.sink<MousePressed>().connect<&PlayerSystem::shootProjectile>(this);
}

void ECS::Systems::PlayerSystem::update(const App::Seconds& deltaTime)
{

}

void ECS::Systems::PlayerSystem::onPlayerAdded(entt::entity entity)
{
    playerEntity = entity;
}

void ECS::Systems::PlayerSystem::movePlayer(const ActionTriggered& event)
{
    switch (event.actionType)
    {
    case App::InputManager::Action::Up:
        dispatcher.trigger(MoveEntity{ playerEntity, Direction::Up });
        break;
    case App::InputManager::Action::Down:
        dispatcher.trigger(MoveEntity{ playerEntity, Direction::Down });
        break;
    case App::InputManager::Action::Right:
        dispatcher.trigger(MoveEntity{ playerEntity, Direction::Right });
        break;
    case App::InputManager::Action::Left:
        dispatcher.trigger(MoveEntity{ playerEntity, Direction::Left });
        break;
    }
}

void ECS::Systems::PlayerSystem::rotatePlayer(const MouseMoved& event)
{
    auto worldPosition = Utility::graphicsToPhysicsPosition(event.position);

    dispatcher.trigger(RotateEntity{ playerEntity, worldPosition });
}

void ECS::Systems::PlayerSystem::shootProjectile(const MousePressed& event)
{
    dispatcher.trigger(ShootProjectile{ playerEntity });
}