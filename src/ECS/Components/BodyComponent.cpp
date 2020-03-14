/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - BodyComponent.cpp
https://inversepalindrome.com/
*/


#include "ECS/Components/BodyComponent.hpp"


ECS::Components::BodyComponent::BodyComponent() :
    body(nullptr),
    AABB({ {FLT_MAX, FLT_MAX}, {-FLT_MAX, -FLT_MAX} })
{
}

ECS::Components::BodyComponent::BodyComponent(b2Body* body) :
    body(body)
{
    computeAABB();
}

void ECS::Components::BodyComponent::initialize(b2World& world)
{
    body = world.CreateBody(&bodyDef);

    for (std::size_t i = 0u; i < fixtureDefs.size(); ++i)
    {
        std::visit([this, i](auto& shape)
            {
                fixtureDefs[i].shape = &shape;
            }, shapes[i]);

        body->CreateFixture(&fixtureDefs[i]);
    }

    computeAABB();
}

void ECS::Components::BodyComponent::setInitializationParameters(const b2BodyDef& bodyDef, const Fixtures& fixtureDefs, const Shapes& shapes)
{
    this->bodyDef = bodyDef;
    this->fixtureDefs = fixtureDefs;
    this->shapes = shapes;
}

b2Body* ECS::Components::BodyComponent::getBody()
{
    return body;
}

const b2Body* ECS::Components::BodyComponent::getBody() const
{
    return body;
}

b2Fixture* ECS::Components::BodyComponent::getFixtureList()
{
    return body->GetFixtureList();
}

const b2Fixture* ECS::Components::BodyComponent::getFixtureList() const
{
    return body->GetFixtureList();
}

b2Vec2 ECS::Components::BodyComponent::getPosition() const
{
    return body->GetPosition();
}

void ECS::Components::BodyComponent::setPosition(const b2Vec2& position)
{
    body->SetTransform(position, body->GetAngle());
}

float ECS::Components::BodyComponent::getAngle() const
{
    return body->GetAngle();
}

void ECS::Components::BodyComponent::setAngle(float angle)
{
    body->SetTransform(body->GetPosition(), angle);
}

b2Vec2 ECS::Components::BodyComponent::getLinearVelocity() const
{
    return body->GetLinearVelocity();
}

void ECS::Components::BodyComponent::setLinearVelocity(const b2Vec2& linearVelocity)
{
    body->SetLinearVelocity(linearVelocity);
}

float ECS::Components::BodyComponent::getAngularVelocity() const
{
    return body->GetAngularVelocity();
}

void ECS::Components::BodyComponent::setAngularVelocity(float angularVelocity)
{
    body->SetAngularVelocity(angularVelocity);
}

float ECS::Components::BodyComponent::getMass() const
{
    return body->GetMass();
}

float ECS::Components::BodyComponent::getInertia() const
{
    return body->GetInertia();
}

b2AABB ECS::Components::BodyComponent::getAABB() const
{
    return AABB;
}

void ECS::Components::BodyComponent::applyLinearImpulse(const b2Vec2& impulse)
{
    body->ApplyLinearImpulse(impulse, body->GetWorldCenter(), true);
}

void ECS::Components::BodyComponent::applyAngularImpulse(float impulse)
{
    body->ApplyAngularImpulse(impulse, true);
}

void* ECS::Components::BodyComponent::getUserData() const
{
    return body->GetUserData();
}

void ECS::Components::BodyComponent::setUserData(void* userData)
{
    body->SetUserData(userData);
}

void ECS::Components::BodyComponent::computeAABB()
{
    for (auto* fixture = body->GetFixtureList(); fixture; fixture = fixture->GetNext())
    {
        for (int child = 0; child < fixture->GetShape()->GetChildCount(); ++child)
        {
            b2Transform transform;
            transform.SetIdentity();

            b2AABB shapeAABB{ { FLT_MAX, FLT_MAX },{ -FLT_MAX, -FLT_MAX } };
            fixture->GetShape()->ComputeAABB(&shapeAABB, transform, child);

            AABB.Combine(shapeAABB);
        }
    }
}