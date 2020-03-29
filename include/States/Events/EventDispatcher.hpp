/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/Events/EventDispatcher.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "States/StateID.hpp"
#include "States/Events/EventID.hpp"

#include <eventpp/hetereventdispatcher.h>


namespace States::Events
{
    using EventDispatcher = eventpp::HeterEventDispatcher<EventID, 
        eventpp::HeterTuple<void(), void(StateID)>>;
}