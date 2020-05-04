/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Utility/IDConversions.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <entt/entt.hpp>


namespace ECS::Utility
{
    entt::entity getEntity(const entt::registry& registry, std::size_t id);
}