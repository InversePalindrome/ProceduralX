/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/DestructionManager.cpp
https://inversepalindrome.com/
*/


#include "ECS/DestructionManager.hpp"
#include "ECS/Components/JointComponent.hpp"


ECS::DestructionManager::DestructionManager(entt::registry& registry) :
    registry(registry)
{
}

void ECS::DestructionManager::SayGoodbye(b2Joint* joint)
{
    registry.view<Components::JointComponent>()
        .each([this, joint](auto entity, auto& jointComp)
            {
                if (jointComp.getJoint() == joint)
                {
                    registry.remove<Components::JointComponent>(entity);
                }
            });
}

void ECS::DestructionManager::SayGoodbye(b2Fixture* fixture)
{

}