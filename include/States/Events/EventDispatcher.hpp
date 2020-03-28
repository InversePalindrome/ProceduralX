/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/Events/EventDispatcher.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "States/Events/Event.hpp"
#include "States/Events/EventPolicies.hpp"

#include <eventpp/eventdispatcher.h>


namespace States::Events
{
    using EventDispatcher = eventpp::EventDispatcher<EventID, void(const Event&), EventPolicies>;
}