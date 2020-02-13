/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SimulationState.cpp
https://inversepalindrome.com/
*/


#include "PhysicsSystem.hpp"
#include "SimulationState.hpp"

#include <imgui.h>


SimulationState::SimulationState(sf::RenderWindow& window, EventDispatcher& eventDispatcher) :
    State(window, eventDispatcher)
{
    systems.push_back(std::make_unique<PhysicsSystem>(registry));
}

void SimulationState::handleEvent(const sf::Event& event)
{

}

void SimulationState::update(const std::chrono::nanoseconds& deltaTime)
{
    for (auto&& system : systems)
    {
        system->update(deltaTime);
    }
}

void SimulationState::render()
{
    bool isOpen = true;

    ImGui::Begin("ProceduralX", &isOpen, ImGuiWindowFlags_AlwaysAutoResize);
    
    addMenuBar();

    ImGui::End();
}

void SimulationState::addMenuBar()
{
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Open", "Ctrl+O"))
            {
                
            }
            if (ImGui::MenuItem("Save", "Ctrl+S"))
            {
                
            }

            ImGui::EndMenu();
        }

        ImGui::EndMenuBar();
    }
}