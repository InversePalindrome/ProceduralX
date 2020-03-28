/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Serializers/EntitySerializer.cpp
https://inversepalindrome.com/
*/


#include "ECS/Serializers/EntitySerializer.hpp"
#include "ECS/Serializers/ComponentSerializers.hpp"
#include "ECS/Components/ComponentList.hpp"

#include <brigand/algorithms/for_each.hpp>

#include <boost/hana/map.hpp>
#include <boost/hana/at_key.hpp>


namespace
{
    using namespace boost;
    using namespace ECS::Serializers;
    using namespace ECS::Components;

    constexpr auto componentMap = hana::make_map(
        hana::make_pair(hana::type_c<SpriteComponent>, [](const auto& registry, auto entity, auto& node)
            {
                serializeSprite(registry.get<SpriteComponent>(entity), node);
            }),
        hana::make_pair(hana::type_c<AnimationComponent>, [](const auto& registry, auto entity, auto& node)
            {
                serializeAnimation(registry.get<AnimationComponent>(entity), node);
            }),
        hana::make_pair(hana::type_c<SoundComponent>, [](const auto& registry, auto entity, auto& node)
            {
                serializeSound(registry.get<SoundComponent>(entity), node);
            }),
        hana::make_pair(hana::type_c<TransformComponent>, [](const auto& registry, auto entity, auto& node)
            {
                serializeTransform(registry.get<TransformComponent>(entity), node);
            }),
        hana::make_pair(hana::type_c<BodyComponent>, [](const auto& registry, auto entity, auto& node)
            {
                serializeBody(registry.get<BodyComponent>(entity), node);
            }),
        hana::make_pair(hana::type_c<SpeedComponent>, [](const auto& registry, auto entity, auto& node)
            {
                serializeSpeed(registry.get<SpeedComponent>(entity), node);
            }),
        hana::make_pair(hana::type_c<AccelerationComponent>, [](const auto& registry, auto entity, auto& node)
            {
                serializeAcceleration(registry.get<AccelerationComponent>(entity), node);
            }),
        hana::make_pair(hana::type_c<ObjectComponent>, [](const auto& registry, auto entity, auto& node)
            {
                serializeObject(registry.get<ObjectComponent>(entity), node);
            }),
        hana::make_pair(hana::type_c<StateComponent>, [](const auto& registry, auto entity, auto& node)
            {
                serializeState(registry.get<StateComponent>(entity), node);
            }),
        hana::make_pair(hana::type_c<WeaponComponent>, [](const auto& registry, auto entity, auto& node)
            {
                serializeWeapon(registry.get<WeaponComponent>(entity), node);
            }),
        hana::make_pair(hana::type_c<DamageComponent>, [](const auto& registry, auto entity, auto& node)
            {
                serializeDamage(registry.get<DamageComponent>(entity), node);
            }),
        hana::make_pair(hana::type_c<HealthComponent>, [](const auto& registry, auto entity, auto& node)
            {
                serializeHealth(registry.get<HealthComponent>(entity), node);
            }),
        hana::make_pair(hana::type_c<Player>, [](const auto& registry, auto, auto& node)
            {
                node.set_name("Player");
            })
    );
}

void ECS::Serializers::serializeEntity(entt::entity entity, const entt::registry& registry, 
    const std::string& filename)
{
    pugi::xml_document doc;

    auto declaration = doc.append_child(pugi::node_declaration);
    declaration.append_attribute("version") = "1.0";
    declaration.append_attribute("encoding") = "UTF-8";

    auto entityNode = doc.append_child("Entity");

    serializeEntity(entity, registry, entityNode);

    doc.save_file(filename.c_str());
}

void ECS::Serializers::serializeEntity(entt::entity entity, const entt::registry& registry, pugi::xml_node& entityNode)
{
    brigand::for_each<Components::ComponentList>([entity, &registry, &entityNode](auto component)
        {
            if (registry.has<decltype(component)::type>(entity))
            {
                auto componentNode = entityNode.append_child();

                ::componentMap[hana::type_c<decltype(component)::type>](registry, entity, componentNode);
            }
        });
}