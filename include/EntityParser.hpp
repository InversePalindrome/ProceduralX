/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - EntityParser.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <entt/entt.hpp>

#include <string>


namespace Parser
{
     entt::entity parseEntity(entt::registry& registry, entt::dispatcher& dispatcher,
         const std::string& filename);
}