/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/IDComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <cstddef>


namespace ECS::Components
{
    class IDComponent
    {
    public:
        IDComponent();
        explicit IDComponent(std::size_t id);

        std::size_t getID() const;
        void setID(std::size_t id);

    private:
        std::size_t id;
    };
}