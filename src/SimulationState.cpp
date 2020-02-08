/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SimulationState.cpp
https://inversepalindrome.com/
*/


#include "SimulationState.hpp"

#include <imgui.h>


SimulationState::SimulationState(sf::RenderWindow& window, EventDispatcher& eventDispatcher) :
    State(window, eventDispatcher)
{
  
}

void SimulationState::handleEvent(const sf::Event& event)
{

}

void SimulationState::update(const std::chrono::nanoseconds& deltaTime)
{

}

void SimulationState::render()
{
    ImGui::Begin("Hello, world!");
    ImGui::Button("Look at this pretty button");
    ImGui::End();
}