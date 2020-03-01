/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - Events.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "Direction.hpp"

#include <box2d/b2_body.h>
#include <box2d/b2_fixture.h>
#include <box2d/b2_edge_shape.h>
#include <box2d/b2_chain_shape.h>
#include <box2d/b2_circle_shape.h>
#include <box2d/b2_polygon_shape.h>

#include <SFML/System/Vector2.hpp>

#include <entt/entt.hpp>

#include <vector>
#include <variant>


struct MoveEntity
{
    entt::entity entity;
    Direction direction;
};

struct RotateEntity
{
    entt::entity entity;
    sf::Vector2f targetPosition;
};

struct CreateBody
{
    entt::entity entity;
    b2BodyDef bodyDef;
    std::vector<b2FixtureDef> fixtureDefs;
    std::vector<std::variant<b2CircleShape, b2EdgeShape, b2PolygonShape, b2ChainShape>> shapes;
};