/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/GameState.cpp
https://inversepalindrome.com/
*/


#include "States/GameState.hpp"
#include "App/Constants.hpp"
#include "ECS/Parsers/LevelParser.hpp"
#include "ECS/Systems/AudioSystem.hpp"
#include "ECS/Systems/InputSystem.hpp"
#include "ECS/Systems/StateSystem.hpp"
#include "ECS/Systems/RenderSystem.hpp"
#include "ECS/Systems/CombatSystem.hpp"
#include "ECS/Systems/PlayerSystem.hpp"
#include "ECS/Systems/PhysicsSystem.hpp"
#include "ECS/Systems/AnimationSystem.hpp"

#include <TGUI/SignalImpl.hpp>
#include <TGUI/Widgets/Button.hpp>


States::GameState::GameState(sf::RenderWindow& window, tgui::Gui& gui, Events::EventDispatcher& eventDispatcher) :
    State(window, gui, eventDispatcher),
    entityFactory(registry),
    systems(registry, dispatcher, entityFactory),
    isPaused(false)
{
    initializeSystems();
    initializeActions();
    initializePauseMenu();

    entityFactory.loadEntities("Resources/XML/Entities.xml");
    ECS::Parsers::parseLevel(registry, "Resources/XML/SpaceLevel.xml");
}

States::GameState::~GameState()
{
    gui.remove(pauseMenuLayout);
}

void States::GameState::handleEvent(const sf::Event& event)
{
    if (!isPaused)
    {
        systems.getSystem<ECS::Systems::InputSystem>()->handleEvent(event);
    }
}

void States::GameState::update(const App::Seconds& deltaTime)
{
    actions.update(window);

    if (!isPaused)
    {
        systems.update(deltaTime);
    }

    if (actions.isActive(Action::Pause))
    {
        pauseMenuLayout->setVisible(!pauseMenuLayout->isVisible());
        isPaused = pauseMenuLayout->isVisible();
    }
}

void States::GameState::render()
{
    systems.getSystem<ECS::Systems::RenderSystem>()->render();
}

void States::GameState::onEnter()
{
    if (isPaused)
    {
        pauseMenuLayout->setVisible(true);
    }
}

void States::GameState::onExit()
{
    pauseMenuLayout->setVisible(false);
}

void States::GameState::initializeSystems()
{
    systems.addSystem<ECS::Systems::InputSystem>();
    systems.addSystem<ECS::Systems::RenderSystem>();
    systems.addSystem<ECS::Systems::AnimationSystem>();
    systems.addSystem<ECS::Systems::AudioSystem>();
    systems.addSystem<ECS::Systems::PhysicsSystem>();
    systems.addSystem<ECS::Systems::PlayerSystem>();
    systems.addSystem<ECS::Systems::CombatSystem>();
    systems.addSystem<ECS::Systems::StateSystem>();

    auto* inputSystem = systems.getSystem<ECS::Systems::InputSystem>();
    inputSystem->setActions(&actions);
    inputSystem->setWindow(&window);
   
    systems.getSystem<ECS::Systems::RenderSystem>()->setWindow(&window);
}

void States::GameState::initializeActions()
{
    actions[Action::MoveUp] = thor::Action(sf::Keyboard::W, thor::Action::Hold);
    actions[Action::MoveDown] = thor::Action(sf::Keyboard::S, thor::Action::Hold);
    actions[Action::MoveRight] = thor::Action(sf::Keyboard::D, thor::Action::Hold);
    actions[Action::MoveLeft] = thor::Action(sf::Keyboard::A, thor::Action::Hold);
    actions[Action::Pause] = thor::Action(sf::Keyboard::Escape, thor::Action::Hold);
}

void States::GameState::initializePauseMenu()
{
    pauseMenuLayout = tgui::VerticalLayout::create();
    pauseMenuLayout->setSize("10%", "10%");
    pauseMenuLayout->setPosition("(parent.size - size) / 2");
    pauseMenuLayout->setVisible(false);

    auto resumeButton = tgui::Button::create("Resume");
    resumeButton->setTextSize(App::FONT_SIZE);
    resumeButton->connect("pressed", [this]() 
        {
            isPaused = false;
            pauseMenuLayout->setVisible(false); 
        });

    auto settingsButton = tgui::Button::create("Settings");
    settingsButton->setTextSize(App::FONT_SIZE);
    settingsButton->connect("pressed", [this]() 
        {
            eventDispatcher.dispatch(Events::EventID::PushState, StateID::Settings);
        });

    auto quitButton = tgui::Button::create("Quit");
    quitButton->setTextSize(App::FONT_SIZE);
    quitButton->connect("pressed", [this]() 
        { 
            eventDispatcher.dispatch(Events::EventID::ChangeState, StateID::Menu);
        });

    pauseMenuLayout->add(resumeButton);
    pauseMenuLayout->add(settingsButton);
    pauseMenuLayout->add(quitButton);

    gui.add(pauseMenuLayout);
}