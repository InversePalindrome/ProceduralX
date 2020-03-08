/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - GameState.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "States/State.hpp"
#include "ECS/Systems/SystemManager.hpp"

#include <entt/entt.hpp>


namespace States
{
    class GameState : public State
    {
    public:
        GameState(sf::RenderWindow& window, EventDispatcher& eventDispatcher);

        virtual void handleEvent(const sf::Event& event) override;
        virtual void update(const App::Seconds& deltaTime) override;
        virtual void render() override;

    private:
        entt::registry registry;
        entt::dispatcher dispatcher;
        ECS::EntityFactory entityFactory;
        ECS::Systems::SystemManager systems;
    };
}