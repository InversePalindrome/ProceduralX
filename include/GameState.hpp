/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - GameState.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "State.hpp"
#include "System.hpp"

#include <entt/entt.hpp>

#include <vector>
#include <memory>


class GameState : public State
{
public:
    GameState(sf::RenderWindow& window, EventDispatcher& eventDispatcher);

    virtual void handleEvent(const sf::Event& event) override;
    virtual void update(const Seconds& deltaTime) override;
    virtual void render() override;

private:
    entt::registry registry;
    entt::dispatcher dispatcher;
    
    std::vector<std::unique_ptr<System>> systems;
};