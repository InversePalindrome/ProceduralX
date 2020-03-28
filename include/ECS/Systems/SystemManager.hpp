/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Systems/SystemManager.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/EntityFactory.hpp"
#include "ECS/Systems/System.hpp"

#include <entt/entt.hpp>

#include <memory>
#include <typeindex>
#include <unordered_map>


namespace ECS::Systems
{
    class SystemManager
    {
    public:
        SystemManager(entt::registry& registry, entt::dispatcher& dispatcher, ECS::EntityFactory& entityFactory);
        SystemManager(const SystemManager&) = delete;
        SystemManager& operator=(const SystemManager&) = delete;
        SystemManager(SystemManager&&) = delete;
        SystemManager& operator=(SystemManager&&) = delete;

        void update(const App::Seconds& deltaTime);

        template<typename T>
        void addSystem();

        template<typename T>
        void removeSystem();

        void clearSystems();

        template<typename T>
        T* getSystem();

        template<typename T>
        const T* getSystem() const;

    private:
        std::unordered_map<std::type_index, std::unique_ptr<System>> systems;

        entt::registry& registry;
        entt::dispatcher& dispatcher;
        ECS::EntityFactory& entityFactory;
    };
}

template<typename T>
void ECS::Systems::SystemManager::addSystem()
{
    systems[typeid(T)] = std::make_unique<T>(registry, dispatcher, entityFactory);
}

template<typename T>
void ECS::Systems::SystemManager::removeSystem()
{
    systems.erase(typeid(T));
}

template<typename T>
T* ECS::Systems::SystemManager::getSystem()
{
    return dynamic_cast<T*>(systems[typeid(T)].get());
}

template<typename T>
const T* ECS::Systems::SystemManager::getSystem() const
{
    return dynamic_cast<const T*>(systems[typeid(T)].get());
}