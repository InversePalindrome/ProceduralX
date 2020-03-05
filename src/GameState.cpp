/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - GameState.cpp
https://inversepalindrome.com/
*/


#include "GameState.hpp"
#include "LevelParser.hpp"
#include "AudioSystem.hpp"
#include "PlayerSystem.hpp"
#include "PhysicsSystem.hpp"
#include "AnimationSystem.hpp"


GameState::GameState(sf::RenderWindow& window, EventDispatcher& eventDispatcher) :
    State(window, eventDispatcher),
    map(200.f, 200.f)
{
    auto renderSystemPtr = std::make_unique<RenderSystem>(registry, dispatcher);
    renderSystemPtr->setWindow(&window);
    renderSystemPtr->setMap(&map);
    renderSystem = renderSystemPtr.get();

    auto inputSystemPtr = std::make_unique<InputSystem>(registry, dispatcher);
    inputSystemPtr->setWindow(&window);
    inputSystem = inputSystemPtr.get();

    systems.push_back(std::move(inputSystemPtr));
    systems.push_back(std::move(renderSystemPtr));
    systems.push_back(std::make_unique<AnimationSystem>(registry, dispatcher));
    systems.push_back(std::make_unique<AudioSystem>(registry, dispatcher));
    systems.push_back(std::make_unique<PhysicsSystem>(registry, dispatcher));
    systems.push_back(std::make_unique<PlayerSystem>(registry, dispatcher));
    
    Parser::parseLevel(registry, "Resources/XML/SpaceLevel.xml");
}

void GameState::handleEvent(const sf::Event& event)
{
    inputSystem->handleEvent(event);
}

void GameState::update(const Seconds& deltaTime)
{
    for (auto&& system : systems)
    {
        system->update(deltaTime);
    }
}

void GameState::render()
{
    renderSystem->render();
}