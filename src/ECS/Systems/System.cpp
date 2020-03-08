/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - System.cpp
https://inversepalindrome.com/
*/


#include "ECS/Systems/System.hpp"


ECS::Systems::System::System(entt::registry& registry, entt::dispatcher& dispatcher, EntityFactory& entityFactory) :
    registry(registry),
    dispatcher(dispatcher),
    entityFactory(entityFactory)
{
}