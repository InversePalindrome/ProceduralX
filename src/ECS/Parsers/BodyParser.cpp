/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Parsers/BodyParser.cpp
https://inversepalindrome.com/
*/


#include "ECS/Parsers/BodyParser.hpp"


b2BodyDef ECS::Parsers::parseBodyDef(const pugi::xml_node& bodyNode)
{
    b2BodyDef bodyDef;
    
    if (auto bodyTypeAttribute = bodyNode.attribute("type"))
    {
        bodyDef.type = static_cast<b2BodyType>(bodyTypeAttribute.as_int());
    }
    if (auto xPositionAttribute = bodyNode.attribute("x"),
        yPositionAttribute = bodyNode.attribute("y");
        xPositionAttribute && yPositionAttribute)
    {
        bodyDef.position = { xPositionAttribute.as_float(), yPositionAttribute.as_float() };
    }
    if (auto angleAttribute = bodyNode.attribute("angle"))
    {
        bodyDef.angle = angleAttribute.as_float();
    }
    if (auto linearDampingAttribute = bodyNode.attribute("linearDamping"))
    {
        bodyDef.linearDamping = linearDampingAttribute.as_float();
    }
    if (auto angularDampingAttribute = bodyNode.attribute("angularDamping"))
    {
        bodyDef.angularVelocity = angularDampingAttribute.as_float();
    }
    if (auto fixedRotationAttribute = bodyNode.attribute("fixedRotation"))
    {
        bodyDef.fixedRotation = fixedRotationAttribute.as_bool();
    }
    if (auto bulletAttribute = bodyNode.attribute("bullet"))
    {
        bodyDef.bullet = bulletAttribute.as_bool();
    }

    return bodyDef;
}

b2FixtureDef ECS::Parsers::parseFixtureDef(const pugi::xml_node& fixtureNode)
{
    b2FixtureDef fixtureDef;

    if(auto densityAttribute = fixtureNode.attribute("density"))
    {
        fixtureDef.density = densityAttribute.as_float();
    }
    if (auto frictionAttribute = fixtureNode.attribute("friction"))
    {
        fixtureDef.friction = frictionAttribute.as_float();
    }
    if (auto restitutionAttribute = fixtureNode.attribute("restitution"))
    {
        fixtureDef.restitution = restitutionAttribute.as_float();
    }
    if (auto sensorAttribute = fixtureNode.attribute("sensor"))
    {
        fixtureDef.isSensor = sensorAttribute.as_bool();
    }

    return fixtureDef;
}

b2CircleShape ECS::Parsers::parseCircle(const pugi::xml_node& circleNode)
{
    b2CircleShape circle;

    if (auto xAttribute = circleNode.attribute("x"))
    {
        circle.m_p.x = xAttribute.as_float();
    }
    if (auto yAttribute = circleNode.attribute("y"))
    {
        circle.m_p.y = yAttribute.as_float();
    }
    if (auto radiusAttribute = circleNode.attribute("radius"))
    {
        circle.m_radius = radiusAttribute.as_float();
    }

    return circle;
}

b2EdgeShape ECS::Parsers::parseEdge(const pugi::xml_node& edgeNode)
{
    b2EdgeShape edge;

    if (auto hasVertex0Attribute = edgeNode.attribute("hasVertex0"))
    {
        if (hasVertex0Attribute.as_bool())
        {
            edge.m_hasVertex0 = true;

            if (auto vertex0XAttribute = edgeNode.attribute("vertex0X"))
            {
                edge.m_vertex0.x = vertex0XAttribute.as_float();
            }
            if (auto vertex0YAttribute = edgeNode.attribute("vertex0Y"))
            {
                edge.m_vertex0.y = vertex0YAttribute.as_float();
            }
        }
        else
        {
            edge.m_hasVertex0 = false;
        }
    }

    if (auto vertex1XAttribute = edgeNode.attribute("vertex1X"))
    {
        edge.m_vertex1.x = vertex1XAttribute.as_float();
    }
    if (auto vertex1YAttribute = edgeNode.attribute("vertex1Y"))
    {
        edge.m_vertex1.y = vertex1YAttribute.as_float();
    }
    if (auto vertex2XAttribute = edgeNode.attribute("vertex2X"))
    {
        edge.m_vertex2.x = vertex2XAttribute.as_float();
    }
    if (auto vertex2YAttribute = edgeNode.attribute("vertex2Y"))
    {
        edge.m_vertex2.y = vertex2YAttribute.as_float();
    }

    if (auto hasVertex3Attribute = edgeNode.attribute("hasVertex3"))
    {
        if (hasVertex3Attribute.as_bool())
        {
            edge.m_hasVertex3 = true;

            if (auto vertex3XAttribute = edgeNode.attribute("vertex3X"))
            {
                edge.m_vertex3.x = vertex3XAttribute.as_float();
            }
            if (auto vertex3YAttribute = edgeNode.attribute("vertex3Y"))
            {
                edge.m_vertex3.y = vertex3YAttribute.as_float();
            }
        }
        else
        {
            edge.m_hasVertex3 = false;
        }
    }

    return edge;
}

b2PolygonShape ECS::Parsers::parsePolygon(const pugi::xml_node& polygonNode)
{
    b2PolygonShape polygon;

    auto vertices = parseVertices(polygonNode);

    if (!vertices.empty())
    {
        polygon.Set(vertices.data(), vertices.size());
    }
    else if (auto widthAttribute = polygonNode.attribute("width"),
        heightAttribute = polygonNode.attribute("height");
        widthAttribute && heightAttribute)
    {
        polygon.SetAsBox(widthAttribute.as_float(1.f), heightAttribute.as_float(1.f));
    }

    return polygon;
}

b2ChainShape ECS::Parsers::parseChain(const pugi::xml_node& chainNode)
{
    b2ChainShape chain;

    auto vertices = parseVertices(chainNode);

    chain.CreateChain(vertices.data(), vertices.size());

    return chain;
}

std::vector<b2Vec2> ECS::Parsers::parseVertices(const pugi::xml_node& verticesNode)
{
    std::vector<b2Vec2> vertices;

    for (const auto pointNode : verticesNode.children("Vertex"))
    {
        b2Vec2 vertex(0.f, 0.f);

        if (auto xAttribute = pointNode.attribute("x"))
        {
            vertex.x = xAttribute.as_float();
        }
        if (auto yAttribute = pointNode.attribute("y"))
        {
            vertex.y = yAttribute.as_float();
        }

        vertices.push_back(vertex);
    }

    return vertices;
}