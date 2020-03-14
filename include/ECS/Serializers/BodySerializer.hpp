/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - BodySerializer.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <box2d/b2_body.h>
#include <box2d/b2_fixture.h>
#include <box2d/b2_edge_shape.h>
#include <box2D/b2_chain_shape.h>
#include <box2D/b2_circle_shape.h>
#include <box2D/b2_polygon_shape.h>

#include <pugixml.hpp>


namespace ECS::Serializers
{
    void serializeBody(const b2Body* body, pugi::xml_node& bodyNode);
    void serializeFixture(const b2Fixture* fixture, pugi::xml_node& fixtureNode);

    void serializeCircle(const b2CircleShape* circle, pugi::xml_node& circleNode);
    void serializeEdge(const b2EdgeShape* edge, pugi::xml_node& edgeNode);
    void serializePolygon(const b2PolygonShape* polygon, pugi::xml_node& polygonNode);
    void serializeChain(const b2ChainShape* chain, pugi::xml_node& chainNode);
}