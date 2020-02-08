/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - EventDispatcher.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "Event.hpp"
#include "EventPolicies.hpp"

#include <eventpp/eventdispatcher.h>


using EventDispatcher = eventpp::EventDispatcher<EventID, void(const Event&), EventPolicies>;