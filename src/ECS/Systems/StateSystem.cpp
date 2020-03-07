/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - StateSystem.cpp
https://inversepalindrome.com/
*/


#include "ECS/Systems/StateSystem.hpp"
#include "ECS/Components/StateComponent.hpp"


ECS::Systems::StateSystem::StateSystem(entt::registry& registry, entt::dispatcher& dispatcher) :
    System(registry, dispatcher)
{
    registry.on_construct<Components::StateComponent>().connect<&StateSystem::onStateAdded>(this);
    dispatcher.sink<ChangeState>().connect<&StateSystem::onChangeState>(this);
}

void ECS::Systems::StateSystem::update(const App::Seconds& deltaTime)
{

}

void ECS::Systems::StateSystem::onStateAdded(entt::entity entity)
{
    const auto& state = registry.get<Components::StateComponent>(entity);

    dispatcher.trigger(StateChanged{ entity, state.getState() });
}

void ECS::Systems::StateSystem::onChangeState(const ChangeState& event)
{
    auto entity = event.entity;
    auto newState = event.state;

    if (registry.has<Components::StateComponent>(entity))
    {
        auto& state = registry.get<Components::StateComponent>(entity);
        state.setState(newState);

        dispatcher.trigger(StateChanged{ entity, newState });
    }
}