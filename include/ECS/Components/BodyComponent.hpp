/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - BodyComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include <box2d/b2_body.h>
#include <box2d/b2_world.h>
#include <box2d/b2_fixture.h>
#include <box2d/b2_edge_shape.h>
#include <box2d/b2_chain_shape.h>
#include <box2d/b2_circle_shape.h>
#include <box2d/b2_polygon_shape.h>

#include <vector>
#include <variant>


namespace ECS::Components
{
    class BodyComponent
    {
    public:
        using Fixtures = std::vector<b2FixtureDef>;
        using Shapes = std::vector<std::variant<b2CircleShape, b2EdgeShape, b2PolygonShape, b2ChainShape>>;

        BodyComponent();
        explicit BodyComponent(b2Body* body);

        void initialize(b2World& world);
        void setInitializationParameters(const b2BodyDef& bodyDef, const Fixtures& fixtureDefs, const Shapes& shapes);

        b2Body* getBody();
        const b2Body* getBody() const;

        b2Fixture* getFixtureList();
        const b2Fixture* getFixtureList() const;

        b2Vec2 getPosition() const;
        void setPosition(const b2Vec2& position);

        float getAngle() const;
        void setAngle(float angle);

        b2Vec2 getLinearVelocity() const;
        void setLinearVelocity(const b2Vec2& linearVelocity);

        float getAngularVelocity() const;
        void setAngularVelocity(float angularVelocity);

        float getMass() const;
        float getInertia() const;

        b2AABB getAABB() const;

        void applyLinearImpulse(const b2Vec2& impulse);
        void applyAngularImpulse(float impulse);

        void* getUserData() const;
        void setUserData(void* userData);

    private:
        b2Body* body;
        b2AABB AABB;
        b2BodyDef bodyDef;
        Fixtures fixtureDefs;
        Shapes shapes;

        void computeAABB();
    };
}