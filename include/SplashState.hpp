/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SplashState.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "State.hpp"

#include <SFML/Graphics/Sprite.hpp>


class SplashState : public State
{
public:
    explicit SplashState(sf::RenderWindow& window);

    virtual void handleEvent(const sf::Event& event) override;
    virtual void update(const std::chrono::milliseconds& deltaTime) override;
    virtual void render() override;

private:
    sf::Sprite splashScreen;
};