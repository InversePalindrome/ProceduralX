/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/EntityFactory.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/EntityID.hpp"
#include "App/ResourceManager.hpp"

#include <entt/entt.hpp>

#include <unordered_map>


namespace ECS
{
    class EntityFactory
    {
    public:
        EntityFactory(entt::registry& registry, App::ResourceManager& resourceManager);
        EntityFactory(const EntityFactory&) = delete;
        EntityFactory& operator=(const EntityFactory&) = delete;
        EntityFactory(EntityFactory&&) = delete;
        EntityFactory& operator=(EntityFactory&&) = delete;

        void loadEntities(const std::string& filename);
        
        void addEntity(EntityID entityID, const std::string& filename);
        void removeEntity(EntityID entityID);
        void clearEntities();

        entt::entity createEntity(EntityID entityID);

    private:
        std::unordered_map<EntityID, std::string> entityFiles;

        entt::registry& registry;
        App::ResourceManager& resourceManager;
    };
}