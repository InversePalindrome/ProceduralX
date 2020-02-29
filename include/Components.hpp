/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - Components.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ComponentTags.hpp"
#include "BodyComponent.hpp"
#include "SpeedComponent.hpp"
#include "SpriteComponent.hpp"
#include "ObjectComponent.hpp"
#include "PositionComponent.hpp"
#include "RotationComponent.hpp"
#include "AnimationComponent.hpp"
#include "AddReferenceWrapper.hpp"
#include "AccelerationComponent.hpp"

#include <brigand/sequences/list.hpp>
#include <brigand/adapted/variant.hpp>
#include <brigand/algorithms/transform.hpp>


using brigand::_1;

using ComponentList = brigand::list<Player, BodyComponent, SpriteComponent, AnimationComponent,
    PositionComponent, ObjectComponent, RotationComponent, SpeedComponent, AccelerationComponent>;

using ComponentReferenceList = brigand::transform<ComponentList, AddReferenceWrapper<_1>>;

using ComponentVariant = brigand::as_variant<ComponentReferenceList>;