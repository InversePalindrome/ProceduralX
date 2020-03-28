/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/TransformComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <SFML/System/Vector2.hpp>


namespace ECS::Components
{
    class TransformComponent
    {
    public:
        TransformComponent();
        TransformComponent(const sf::Vector2f& position, float angle);

        sf::Vector2f getPosition() const;
        void setPosition(const sf::Vector2f& position);

        float getAngle() const;
        void setAngle(float angle);

    private:
        sf::Vector2f position;
        float angle;
    };
}