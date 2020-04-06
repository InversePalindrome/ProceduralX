/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/EntityFactory.cpp
https://inversepalindrome.com/
*/


#include "ECS/EntityFactory.hpp"
#include "ECS/Parsers/EntityParser.hpp"

#include <magic_enum.hpp>


ECS::EntityFactory::EntityFactory(entt::registry& registry, App::ResourceManager& resourceManager) :
    registry(registry),
    resourceManager(resourceManager)
{
}

void ECS::EntityFactory::loadEntities(const std::string& filename)
{
    if (pugi::xml_document doc; doc.load_file(filename.c_str()))
    {
        if (auto entitiesNode = doc.child("Entities"))
        {
            for (auto entityNode : entitiesNode.children())
            {
                auto entityOptional = magic_enum::enum_cast<EntityID>(entityNode.name());

                if (entityOptional.has_value())
                {
                    entityFiles[entityOptional.value()] = entityNode.text().as_string();
                }
            }
        }
    }
}

void ECS::EntityFactory::addEntity(EntityID entityID, const std::string& filename)
{
    entityFiles[entityID] = filename;
}

void ECS::EntityFactory::removeEntity(EntityID entityID)
{
    entityFiles.erase(entityID);
}

void ECS::EntityFactory::clearEntities()
{
    entityFiles.clear();
}

entt::entity ECS::EntityFactory::createEntity(EntityID entityID)
{
    return Parsers::parseEntity(registry, resourceManager, entityFiles.at(entityID));
}