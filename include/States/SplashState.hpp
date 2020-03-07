/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SplashState.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "States/State.hpp"

#include <SFML/Graphics/Sprite.hpp>


namespace States
{
    class SplashState : public State
    {
    public:
        SplashState(sf::RenderWindow& window, EventDispatcher& eventDispatcher);

        virtual void handleEvent(const sf::Event& event) override;
        virtual void update(const App::Seconds& deltaTime) override;
        virtual void render() override;

    private:
        sf::Sprite splashScreen;

        App::Seconds splashTime;
    };
}