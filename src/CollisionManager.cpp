/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - CollisionManager.cpp
https://inversepalindrome.com/
*/


#include "CollisionManager.hpp"


CollisionManager::CollisionManager(entt::dispatcher& dispatcher) :
    dispatcher(dispatcher)
{
}

void CollisionManager::BeginContact(b2Contact* contact)
{
}

void CollisionManager::EndContact(b2Contact* contact)
{

}

void CollisionManager::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{

}

void CollisionManager::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{

}