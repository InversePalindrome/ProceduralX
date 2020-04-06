/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/GameState.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "States/State.hpp"
#include "ECS/Action.hpp"
#include "ECS/Systems/SystemManager.hpp"

#include <TGUI/Widgets/VerticalLayout.hpp>

#include <Thor/Input/ActionMap.hpp>

#include <entt/entt.hpp>


namespace States
{
    class GameState : public State
    {
    public:
        explicit GameState(StateData& stateData);

        virtual ~GameState() override;

        virtual void handleEvent(const sf::Event& event) override;
        virtual void update(const App::Seconds& deltaTime) override;
        virtual void render() override;
        virtual void onEnter() override;
        virtual void onExit() override;

    private:
        entt::registry registry;
        entt::dispatcher dispatcher;
        ECS::EntityFactory entityFactory;
        ECS::Systems::SystemManager systems;

        thor::ActionMap<Action> actions;

        tgui::VerticalLayout::Ptr pauseMenuLayout;
        bool isPaused;

        void initializeSystems();
        void initializeActions();
        void initializePauseMenu();
    };
}