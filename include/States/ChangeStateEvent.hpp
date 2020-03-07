/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ChangeStateEvent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "States/Event.hpp"
#include "States/StateID.hpp"


namespace States
{
    struct ChangeStateEvent : public Event
    {
        ChangeStateEvent(EventID eventID, StateID transitionState) :
            Event(eventID),
            transitionState(transitionState) {};

        StateID transitionState;
    };
}