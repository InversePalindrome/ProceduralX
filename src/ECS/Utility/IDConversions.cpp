/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Utility/IDConversions.cpp
https://inversepalindrome.com/
*/


#include "ECS/Utility/IDConversions.hpp"
#include "ECS/Components/IDComponent.hpp"


entt::entity ECS::Utility::getEntity(const entt::registry& registry, std::size_t id)
{
    auto foundEntity = entt::entity{ entt::null };

    registry.each([&registry, &foundEntity, id](auto entity)
        {
            if (registry.has<Components::IDComponent>(entity))
            {
                const auto& idComponent = registry.get<Components::IDComponent>(entity);

                if (id == idComponent.getID())
                {
                    foundEntity = entity;
                }
            }
        });

    return foundEntity;
}