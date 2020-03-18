/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ComponentList.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ECS/Components/BodyComponent.hpp"
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
#include "ECS/Components/PositionComponent.hpp"
#include "ECS/Components/RotationComponent.hpp"
#include "ECS/Components/ComponentTags.hpp"

#include <brigand/sequences/list.hpp>


namespace ECS::Components
{
    using ComponentList = brigand::list<BodyComponent, SpeedComponent, StateComponent, SoundComponent,
    SpriteComponent, ObjectComponent, WeaponComponent, DamageComponent, HealthComponent, AnimationComponent,
    AccelerationComponent, PositionComponent, RotationComponent, Player>;
}