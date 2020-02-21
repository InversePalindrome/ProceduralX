/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - AddReferenceWrapper.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <functional>


template<typename T>
struct AddReferenceWrapper
{
    using type = std::reference_wrapper<T>;
};