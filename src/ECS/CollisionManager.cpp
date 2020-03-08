/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - CollisionManager.cpp
https://inversepalindrome.com/
*/



#include "ECS/Components/ObjectComponent.hpp"
#include "ECS/CollisionManager.hpp"


ECS::CollisionManager::CollisionManager(entt::registry& registry, entt::dispatcher& dispatcher) :
    registry(registry),
    dispatcher(dispatcher)
{
}

void ECS::CollisionManager::BeginContact(b2Contact* contact)
{
    auto entityA = static_cast<entt::registry::entity_type>(reinterpret_cast<std::uint32_t>
        (contact->GetFixtureA()->GetBody()->GetUserData()));
    auto entityB = static_cast<entt::registry::entity_type>(reinterpret_cast<std::uint32_t>
        (contact->GetFixtureB()->GetBody()->GetUserData()));

    if (auto collisionPair = getCollisionPair(entityA, entityB, ObjectType::Player, ObjectType::Enemy))
    {

    }
}

void ECS::CollisionManager::EndContact(b2Contact* contact)
{

}

void ECS::CollisionManager::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{

}

void ECS::CollisionManager::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{

}

std::optional<std::pair<entt::entity, entt::entity>> ECS::CollisionManager::getCollisionPair
(entt::entity entityA, entt::entity entityB, ObjectType objectTypeA, ObjectType objectTypeB)
{
    if (registry.has<Components::ObjectComponent>(entityA) && registry.has<Components::ObjectComponent>(entityB))
    {
        const auto& objectA = registry.get<Components::ObjectComponent>(entityA);
        const auto& objectB = registry.get<Components::ObjectComponent>(entityB);

        if (objectA.getObjectType() == objectTypeA && objectB.getObjectType() == objectTypeB)
        {
            return { { entityA, entityB } };
        }
        else if (objectA.getObjectType() == objectTypeB && objectB.getObjectType() == objectTypeA)
        {
            return { {entityB, entityA} };
        }
    }

    return {};
}