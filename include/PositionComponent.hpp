/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - PositionComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <SFML/System/Vector2.hpp>


class PositionComponent
{
public:
    PositionComponent();
    explicit PositionComponent(const sf::Vector2f& position);
    PositionComponent(float xPosition, float yPosition);

    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& position);

private:
    sf::Vector2f position;
};