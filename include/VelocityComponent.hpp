/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - VelocityComponent.cpp
https://inversepalindrome.com/
*/


#pragma once

#include <SFML/System/Vector2.hpp>


class VelocityComponent
{
public:
    VelocityComponent();
    explicit VelocityComponent(const sf::Vector2f& velocity);
    VelocityComponent(float xVelocity, float yVelocity);

    sf::Vector2f getVelocity() const;
    void setVelocity(const sf::Vector2f& velocity);

private:
    sf::Vector2f velocity;
};