/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/AccelerationComponent.hpp
https://inversepalindrome.com/
*/


#pragma once


namespace ECS::Components
{
    class AccelerationComponent
    {
    public:
        AccelerationComponent();
        AccelerationComponent(float linearAcceleration, float angularAcceleration);

        float getLinearAcceleration() const;
        void setLinearAcceleration(float linearAcceleration);

        float getAngularAcceleration() const;
        void setAngularAcceleration(float angularAcceleration);

    private:
        float linearAcceleration;
        float angularAcceleration;
    };
}