/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - Components.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "ComponentTags.hpp"
#include "BodyComponent.hpp"
#include "SpriteComponent.hpp"
#include "PositionComponent.hpp"
#include "VelocityComponent.hpp"

#include <brigand/sequences/list.hpp>
#include <brigand/adapted/variant.hpp>


using ComponentList = brigand::list<Player, BodyComponent, SpriteComponent, PositionComponent, VelocityComponent>;

using ComponentVariant = brigand::as_variant<ComponentList>;