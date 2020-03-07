/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - GameState.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "States/State.hpp"
#include "ECS/Map.hpp"
#include "ECS/Systems/System.hpp"
#include "ECS/Systems/InputSystem.hpp"
#include "ECS/Systems/RenderSystem.hpp"

#include <entt/entt.hpp>

#include <vector>
#include <memory>


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

        std::vector<std::unique_ptr<ECS::Systems::System>> systems;

        ECS::Systems::RenderSystem* renderSystem;
        ECS::Systems::InputSystem* inputSystem;

        ECS::Map map;
    };
}