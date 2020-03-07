/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - Event.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "States/EventID.hpp"


namespace States
{
    struct Event
    {
        explicit Event(EventID eventID) :
            eventID(eventID) {};

        virtual ~Event() {};

        EventID eventID;
    };
}