/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - BodyParser.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <box2d/b2_body.h>
#include <box2d/b2_math.h>
#include <box2d/b2_fixture.h>
#include <box2d/b2_edge_shape.h>
#include <box2d/b2_chain_shape.h>
#include <box2d/b2_circle_shape.h>
#include <box2d/b2_polygon_shape.h>

#include <pugixml.hpp>

#include <vector>


namespace ECS::Parsers
{
    b2BodyDef parseBodyDef(const pugi::xml_node& bodyNode);
    b2FixtureDef parseFixtureDef(const pugi::xml_node& fixtureNode);

    b2CircleShape parseCircle(const pugi::xml_node& circleNode);
    b2EdgeShape parseEdge(const pugi::xml_node& edgeNode);
    b2PolygonShape parsePolygon(const pugi::xml_node& polygonNode);
    b2ChainShape parseChain(const pugi::xml_node& chainNode);

    std::vector<b2Vec2> parseVertices(const pugi::xml_node& verticesNode);
}