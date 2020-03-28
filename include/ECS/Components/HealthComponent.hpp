/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/HealthComponent.hpp
https://inversepalindrome.com/
*/


#pragma once


namespace ECS::Components
{
    class HealthComponent
    {
    public:
        HealthComponent();
        explicit HealthComponent(float health);

        float getHealth() const;
        void setHealth(float health);

    private:
        float health;
    };
}