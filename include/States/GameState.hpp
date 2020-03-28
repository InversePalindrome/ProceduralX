/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/GameState.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "States/State.hpp"
#include "States/GUI/PauseMenu.hpp"
#include "ECS/Systems/SystemManager.hpp"

#include <entt/entt.hpp>


namespace States
{
    class GameState : public State
    {
    public:
        GameState(sf::RenderWindow& window, tgui::Gui& gui, Events::EventDispatcher& eventDispatcher);

        virtual void handleEvent(const sf::Event& event) override;
        virtual void update(const App::Seconds& deltaTime) override;
        virtual void render() override;

    private:
        entt::registry registry;
        entt::dispatcher dispatcher;
        ECS::EntityFactory entityFactory;
        ECS::Systems::SystemManager systems;

        GUI::PauseMenu* pauseMenu;
    };
}