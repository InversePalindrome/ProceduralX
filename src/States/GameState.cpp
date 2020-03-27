/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - GameState.cpp
https://inversepalindrome.com/
*/


#include "States/GameState.hpp"
#include "ECS/Parsers/LevelParser.hpp"
#include "ECS/Systems/AudioSystem.hpp"
#include "ECS/Systems/InputSystem.hpp"
#include "ECS/Systems/StateSystem.hpp"
#include "ECS/Systems/RenderSystem.hpp"
#include "ECS/Systems/CombatSystem.hpp"
#include "ECS/Systems/PlayerSystem.hpp"
#include "ECS/Systems/PhysicsSystem.hpp"
#include "ECS/Systems/AnimationSystem.hpp"


States::GameState::GameState(sf::RenderWindow& window, tgui::Gui& gui, EventDispatcher& eventDispatcher) :
    State(window, gui, eventDispatcher),
    entityFactory(registry),
    systems(registry, dispatcher, entityFactory)
{
    systems.addSystem<ECS::Systems::InputSystem>();
    systems.addSystem<ECS::Systems::RenderSystem>();
    systems.addSystem<ECS::Systems::AnimationSystem>();
    systems.addSystem<ECS::Systems::AudioSystem>();
    systems.addSystem<ECS::Systems::PhysicsSystem>();
    systems.addSystem<ECS::Systems::PlayerSystem>();
    systems.addSystem<ECS::Systems::CombatSystem>();
    systems.addSystem<ECS::Systems::StateSystem>();
    
    systems.getSystem<ECS::Systems::InputSystem>()->setWindow(&window);
    systems.getSystem<ECS::Systems::RenderSystem>()->setWindow(&window);

    entityFactory.loadEntities("Resources/XML/Entities.xml");
    ECS::Parsers::parseLevel(registry, "Resources/XML/SpaceLevel.xml");
}

void States::GameState::handleEvent(const sf::Event& event)
{
    systems.getSystem<ECS::Systems::InputSystem>()->handleEvent(event);
}

void States::GameState::update(const App::Seconds& deltaTime)
{
    systems.update(deltaTime);
}

void States::GameState::render()
{
    systems.getSystem<ECS::Systems::RenderSystem>()->render();
}