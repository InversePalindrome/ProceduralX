/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ChangeStateEvent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "Event.hpp"
#include "StateID.hpp"


struct ChangeStateEvent : public Event
{
    ChangeStateEvent(EventID eventID, StateID transitionState) :
        Event(eventID),
        transitionState(transitionState) {};

    StateID transitionState;
};