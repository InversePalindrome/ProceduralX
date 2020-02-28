/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ZOrderComparator.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "SpriteComponent.hpp"

#include <functional>


struct ZOrderComparator
{
    inline bool operator()(const std::reference_wrapper<SpriteComponent>& sprite1, const std::reference_wrapper<SpriteComponent>& sprite2) const
    {
        return sprite1.get().getZOrder() < sprite2.get().getZOrder();
    }
};