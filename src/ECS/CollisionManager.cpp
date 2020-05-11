/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/CollisionManager.cpp
https://inversepalindrome.com/
*/


#include "ECS/Events.hpp"
#include "ECS/CollisionManager.hpp"
#include "ECS/Components/ObjectComponent.hpp"


ECS::CollisionManager::CollisionManager(entt::registry& registry, entt::dispatcher& dispatcher) :
    registry(registry),
    dispatcher(dispatcher)
{
}

void ECS::CollisionManager::BeginContact(b2Contact* contact)
{
    auto entityA = castUserDataToEntity(contact->GetFixtureA()->GetBody()->GetUserData());
    auto entityB = castUserDataToEntity(contact->GetFixtureB()->GetBody()->GetUserData());

    if (isCollisionPairValid(registry, entityA, entityB))
    {
        auto objectA = registry.get<Components::ObjectComponent>(entityA).getObjectType();
        auto objectB = registry.get<Components::ObjectComponent>(entityB).getObjectType();;

        if (auto collisionPair = getCollisionPair(entityA, entityB, objectA, objectB,
            ObjectType::Projectile, ObjectType::Player | ObjectType::Enemy))
        {
            auto [projectile, victim] = *collisionPair;

            dispatcher.trigger(CombatOccurred{ projectile, victim });
        }
        if (auto collisionPair = getCollisionPair(entityA, entityB, objectA, objectB,
            ObjectType::Enemy | ObjectType::Planet, ObjectType::Path))
        {
            auto [crossingEntity, pathEntity] = *collisionPair;

            dispatcher.trigger(CrossedPathPoint{ crossingEntity, pathEntity });

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

entt::entity ECS::castUserDataToEntity(void* userData)
{
    return static_cast<entt::registry::entity_type>(reinterpret_cast<std::uint32_t>(userData));
}

bool ECS::isCollisionPairValid(const entt::registry& registry, entt::entity entityA, entt::entity entityB)
{
    return registry.valid(entityA) && registry.valid(entityB) && registry.has<Components::ObjectComponent>(entityA)
        && registry.has<Components::ObjectComponent>(entityB);
}