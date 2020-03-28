/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/Events/Event.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "States/Events//EventID.hpp"


namespace States::Events
{
    struct Event
    {
        explicit Event(EventID eventID) :
            eventID(eventID) {};

        virtual ~Event() {};

        EventID eventID;
    };
}