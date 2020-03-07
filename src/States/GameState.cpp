/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - GameState.cpp
https://inversepalindrome.com/
*/


#include "States/GameState.hpp"
#include "ECS/Parsers/LevelParser.hpp"
#include "ECS/Systems/AudioSystem.hpp"
#include "ECS/Systems/StateSystem.hpp"
#include "ECS/Systems/CombatSystem.hpp"
#include "ECS/Systems/PlayerSystem.hpp"
#include "ECS/Systems/PhysicsSystem.hpp"
#include "ECS/Systems/AnimationSystem.hpp"


States::GameState::GameState(sf::RenderWindow& window, EventDispatcher& eventDispatcher) :
    State(window, eventDispatcher),
    map(200.f, 200.f)
{
    auto renderSystemPtr = std::make_unique<ECS::Systems::RenderSystem>(registry, dispatcher);
    renderSystemPtr->setWindow(&window);
    renderSystemPtr->setMap(&map);
    renderSystem = renderSystemPtr.get();

    auto inputSystemPtr = std::make_unique<ECS::Systems::InputSystem>(registry, dispatcher);
    inputSystemPtr->setWindow(&window);
    inputSystem = inputSystemPtr.get();

    systems.push_back(std::move(inputSystemPtr));
    systems.push_back(std::move(renderSystemPtr));
    systems.push_back(std::make_unique<ECS::Systems::AnimationSystem>(registry, dispatcher));
    systems.push_back(std::make_unique<ECS::Systems::AudioSystem>(registry, dispatcher));
    systems.push_back(std::make_unique<ECS::Systems::PhysicsSystem>(registry, dispatcher));
    systems.push_back(std::make_unique<ECS::Systems::PlayerSystem>(registry, dispatcher));
    systems.push_back(std::make_unique<ECS::Systems::CombatSystem>(registry, dispatcher));
    systems.push_back(std::make_unique<ECS::Systems::StateSystem>(registry, dispatcher));
    
    ECS::Parsers::parseLevel(registry, "Resources/XML/SpaceLevel.xml");
}

void States::GameState::handleEvent(const sf::Event& event)
{
    inputSystem->handleEvent(event);
}

void States::GameState::update(const App::Seconds& deltaTime)
{
    for (auto&& system : systems)
    {
        system->update(deltaTime);
    }
}

void States::GameState::render()
{
    renderSystem->render();
}