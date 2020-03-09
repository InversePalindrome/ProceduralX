/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - DamageComponent.hpp
https://inversepalindrome.com/
*/


#pragma once


namespace ECS::Components
{
    class DamageComponent
    {
    public:
        DamageComponent();
        explicit DamageComponent(float damage);

        float getDamage() const;
        void setDamage(float damage);

    private:
        float damage;
    };
}