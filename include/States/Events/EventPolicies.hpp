/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/Events/EventPolicies.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "States/Events/Event.hpp"


namespace States::Events
{
    struct EventPolicies
    {
        static EventID getEvent(const Event& event)
        {
            return event.eventID;
        }
    };
}