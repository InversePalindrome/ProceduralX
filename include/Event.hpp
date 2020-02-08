/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - Event.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "EventID.hpp"


struct Event
{
    explicit Event(EventID eventID) :
        eventID(eventID) {};

    virtual ~Event() {};

    EventID eventID;
};