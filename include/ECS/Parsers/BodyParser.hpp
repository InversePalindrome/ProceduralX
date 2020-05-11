/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Parsers/BodyParser.hpp
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
    void parseBodyDef(b2BodyDef& bodyDef, const pugi::xml_node& bodyNode);
    void parseFixtureDef(b2FixtureDef& fixtureDef, const pugi::xml_node& fixtureNode);

    void parseCircle(b2CircleShape& circle, const pugi::xml_node& circleNode);
    void parseEdge(b2EdgeShape& edge, const pugi::xml_node& edgeNode);
    void parsePolygon(b2PolygonShape& polygon, const pugi::xml_node& polygonNode);
    void parseChain(b2ChainShape& chain, const pugi::xml_node& chainNode);

    void parseVertices(std::vector<b2Vec2>& vertices, const pugi::xml_node& verticesNode);
}