/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/StateComponent.hpp
https://inversepalindrome.com/
*
*/


#pragma once

#include "ECS/State.hpp"


namespace ECS::Components
{
    class StateComponent
    {
    public:
        StateComponent();
        explicit StateComponent(State state);

        State getState() const;
        void setState(State state);

    private:
        State state;
    };
}