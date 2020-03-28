/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/State.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "App/Seconds.hpp"
#include "States/Events/EventDispatcher.hpp"

#include <TGUI/Gui.hpp>

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


namespace States
{
    class State
    {
    public:
        State(sf::RenderWindow& window, tgui::Gui& gui, Events::EventDispatcher& eventDispatcher);
        State(const State&) = delete;
        State& operator=(const State&) = delete;
        State(State&&) = delete;
        State& operator=(State&&) = delete;

        virtual ~State() = default;

        virtual void handleEvent(const sf::Event& event) = 0;
        virtual void update(const App::Seconds& deltaTime) = 0;
        virtual void render() = 0;

    protected:
        sf::RenderWindow& window;
        tgui::Gui& gui;
        Events::EventDispatcher& eventDispatcher;
    };
}