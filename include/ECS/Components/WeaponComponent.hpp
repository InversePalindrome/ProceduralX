/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/WeaponComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/EntityID.hpp"
#include "App/Seconds.hpp"


namespace ECS::Components
{
    class WeaponComponent
    {
    public:
        WeaponComponent();

        EntityID getProjectile() const;
        void setProjectile(EntityID projectile);

        App::Seconds getReloadTime() const;
        void setReloadTime(const App::Seconds& reloadTime);

    private:
        EntityID projectile;
        App::Seconds reloadTime;
    };
}