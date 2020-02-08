/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - EventPolicies.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "Event.hpp"


struct EventPolicies
{
    static EventID getEvent(const Event& event)
    {
        return event.eventID;
    }
};