/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Utility/AngleConversions.hpp
https://inversepalindrome.com/
*/


#pragma once


#include <boost/math/constants/constants.hpp>


namespace ECS::Utility
{
    template<typename T>
    T degreesToRadians(T degrees)
    {
        return degrees * boost::math::constants::pi<T>() / (T)180;
    }

    template<typename T>
    T radiansToDegrees(T radians)
    {
        return radians * (T)180 / boost::math::constants::pi<T>();
    }
}
