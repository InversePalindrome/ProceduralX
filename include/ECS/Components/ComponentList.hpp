/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Components/ComponentList.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/Components/IDComponent.hpp"
#include "ECS/Components/BodyComponent.hpp"
#include "ECS/Components/JointComponent.hpp"
#include "ECS/Components/SpeedComponent.hpp"
#include "ECS/Components/StateComponent.hpp"
#include "ECS/Components/SoundComponent.hpp"
#include "ECS/Components/SpriteComponent.hpp"
#include "ECS/Components/ObjectComponent.hpp"
#include "ECS/Components/WeaponComponent.hpp"
#include "ECS/Components/DamageComponent.hpp"
#include "ECS/Components/HealthComponent.hpp"
#include "ECS/Components/AnimationComponent.hpp"
#include "ECS/Components/AccelerationComponent.hpp"
#include "ECS/Components/TransformComponent.hpp"
#include "ECS/Components/SatelliteComponent.hpp"
#include "ECS/Components/PathComponent.hpp"

#include <brigand/sequences/list.hpp>


namespace ECS::Components
{
    using ComponentList = brigand::list<IDComponent, BodyComponent, JointComponent, SpeedComponent, 
        StateComponent, SoundComponent, SpriteComponent, ObjectComponent, WeaponComponent, DamageComponent,
        HealthComponent, AnimationComponent, AccelerationComponent, TransformComponent, SatelliteComponent,
        PathComponent, entt::tag<"Player"_hs>>;
}