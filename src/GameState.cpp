/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - GameState.cpp
https://inversepalindrome.com/
*/


#include "GameState.hpp"
#include "InputSystem.hpp"
#include "EntityParser.hpp"
#include "RenderSystem.hpp"
#include "PhysicsSystem.hpp"


GameState::GameState(sf::RenderWindow& window, EventDispatcher& eventDispatcher) :
    State(window, eventDispatcher)
{
    auto renderSystem = std::make_unique<RenderSystem>(registry, dispatcher);
    renderSystem->setWindow(&window);

    systems.push_back(std::make_unique<InputSystem>(registry, dispatcher));
    systems.push_back(std::move(renderSystem));
    systems.push_back(std::make_unique<PhysicsSystem>(registry, dispatcher));

    Parser::parseEntity(registry, dispatcher, "Resources/XML/Spaceship.xml");
}

void GameState::handleEvent(const sf::Event& event)
{

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
    
}