/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SimulationState.cpp
https://inversepalindrome.com/
*/


#include "InputSystem.hpp"
#include "RenderSystem.hpp"
#include "PhysicsSystem.hpp"
#include "SimulationState.hpp"

#include <imgui.h>


SimulationState::SimulationState(sf::RenderWindow& window, EventDispatcher& eventDispatcher) :
    State(window, eventDispatcher)
{
    auto renderSystem = std::make_unique<RenderSystem>(registry);
    renderSystem->setWindow(&window);

    systems.push_back(std::make_unique<InputSystem>(registry));
    systems.push_back(std::move(renderSystem));
    systems.push_back(std::make_unique<PhysicsSystem>(registry));
}

void SimulationState::handleEvent(const sf::Event& event)
{

}

void SimulationState::update(const Seconds& deltaTime)
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