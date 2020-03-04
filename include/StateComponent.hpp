/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - StateComponent.hpp
https://inversepalindrome.com/
*
*/


#pragma once

#include "EntityState.hpp"


class StateComponent
{
public:
    StateComponent();
    explicit StateComponent(EntityState state);

    EntityState getState() const;
    void setState(EntityState state);

private:
    EntityState state;
};