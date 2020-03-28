/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/CollisionManager.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/ObjectComponent.hpp"
#include "ECS/Systems/Events.hpp"
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

    if (!registry.valid(entityA) || !registry.valid(entityB) || !registry.has
        <Components::ObjectComponent>(entityA) || !registry.has<Components::ObjectComponent>(entityB))
    {
        return;
    }

    auto objectA = registry.get<Components::ObjectComponent>(entityA).getObjectType();
    auto objectB = registry.get<Components::ObjectComponent>(entityB).getObjectType();;

    if (auto collisionPair = getCollisionPair(entityA, entityB, objectA, objectB,
        ObjectType::Projectile, ObjectType::Player | ObjectType::Enemy))
    {
        auto [projectile, victim] = *collisionPair;

        dispatcher.trigger(ECS::Systems::CombatOccurred{ projectile, victim });
    }
    if (objectA & ObjectType::Projectile)
    {
        registry.destroy(entityA);
    }
    if (objectB & ObjectType::Projectile)
    {
        registry.destroy(entityB);
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

std::optional<std::pair<entt::entity, entt::entity>> ECS::getCollisionPair(entt::entity entityA, entt::entity entityB,
 flags::flags<ObjectType> objectTypeA, flags::flags<ObjectType> objectTypeB,
 flags::flags<ObjectType> orderedObjectTypeA, flags::flags<ObjectType> orderedObjectTypeB)
{
    if (objectTypeA & orderedObjectTypeA && objectTypeB & orderedObjectTypeB)
    {
        return { { entityA, entityB } };
    }
    else if (objectTypeA & orderedObjectTypeB && objectTypeB & orderedObjectTypeA)
    {
        return { { entityB, entityA } };
    }

    return {};
}