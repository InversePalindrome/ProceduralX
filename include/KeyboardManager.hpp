/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - KeyboardManager.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <Thor/Input/ActionMap.hpp>


class KeyboardManager
{
public:
    enum class Action{};

private:
    thor::ActionMap<Action> keyBindings;
};