/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/Events/ChangeStateEvent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "States/Events/Event.hpp"
#include "States/StateID.hpp"


namespace States::Events
{
    struct ChangeStateEvent : public Event
    {
        ChangeStateEvent(EventID eventID, StateID transitionState) :
            Event(eventID),
            transitionState(transitionState) {};

        StateID transitionState;
    };
}