/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - StateComponent.cpp
https://inversepalindrome.com/
*/


#include "StateComponent.hpp"


StateComponent::StateComponent() :
    state(EntityState::Idle)
{
}

StateComponent::StateComponent(EntityState state) :
    state(state)
{
}

EntityState StateComponent::getState() const
{
    return state;
}

void StateComponent::setState(EntityState state)
{
    this->state = state;
}