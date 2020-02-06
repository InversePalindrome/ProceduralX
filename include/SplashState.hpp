/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SplashState.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "State.hpp"


class SplashState : public State
{
public:
    virtual void handleEvent(const sf::Event& event) override;
    virtual void update(const std::chrono::milliseconds& deltaTime) override;
    virtual void render() override;

private:
};