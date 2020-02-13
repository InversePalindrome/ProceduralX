/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SimulationState.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "State.hpp"
#include "System.hpp"

#include <entt/entt.hpp>

#include <vector>
#include <memory>


class SimulationState : public State
{
public:
    SimulationState(sf::RenderWindow& window, EventDispatcher& eventDispatcher);

    virtual void handleEvent(const sf::Event& event) override;
    virtual void update(const std::chrono::nanoseconds& deltaTime) override;
    virtual void render() override;

private:
    entt::registry registry;
    std::vector<std::unique_ptr<System>> systems;

    void addMenuBar();
};