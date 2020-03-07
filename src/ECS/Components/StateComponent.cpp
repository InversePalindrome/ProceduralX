/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - StateComponent.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/StateComponent.hpp"


ECS::Components::StateComponent::StateComponent() :
    state(State::Idle)
{
}

ECS::Components::StateComponent::StateComponent(State state) :
    state(state)
{
}

ECS::State ECS::Components::StateComponent::getState() const
{
    return state;
}

void ECS::Components::StateComponent::setState(State state)
{
    this->state = state;
}