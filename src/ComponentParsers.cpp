/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ComponentParsers.cpp
https://inversepalindrome.com/
*/


#include "Events.hpp"
#include "BodyParser.hpp"
#include "ComponentTags.hpp"
#include "BodyComponent.hpp"
#include "SpeedComponent.hpp"
#include "SpriteComponent.hpp"
#include "ObjectComponent.hpp"
#include "ResourceManager.hpp"
#include "PositionComponent.hpp"
#include "RotationComponent.hpp"
#include "ComponentParsers.hpp"
#include "AnimationComponent.hpp"
#include "AccelerationComponent.hpp"

#include <magic_enum.hpp>

#include <variant>


void Parser::parseSprite(entt::registry& registry, entt::entity entity, const pugi::xml_node& spriteNode)
{
    SpriteComponent sprite;

    if (auto textureAttribute = spriteNode.attribute("texture"))
    {
        auto textureID = magic_enum::enum_cast<TextureID>(textureAttribute.as_string());
 
        if (textureID.has_value())
        {
            sprite.setTexture(ResourceManager::getInstance().getTexture(textureID.value()));
        }
    }
    if (auto textureXAttribute = spriteNode.attribute("textureX"),
        textureYAttribute = spriteNode.attribute("textureY"),
        textureWidthAttribute = spriteNode.attribute("textureWidth"),
        textureHeightAttribute = spriteNode.attribute("textureHeight");
        textureXAttribute && textureYAttribute && textureWidthAttribute && textureHeightAttribute)
    {
        sprite.setTextureRect({ textureXAttribute.as_int(), textureYAttribute.as_int(), textureWidthAttribute.as_int(), textureHeightAttribute.as_int() });
    }
    if (auto scaleXAttribute = spriteNode.attribute("scaleX"),
        scaleYAttribute = spriteNode.attribute("scaleY");
        scaleXAttribute && scaleYAttribute)
    {
        sprite.setScale(scaleXAttribute.as_float(), scaleYAttribute.as_float());
    }
    if (auto originScaleXAttribute = spriteNode.attribute("originScaleY"),
        originScaleYAttribute = spriteNode.attribute("originScaleX");
        originScaleXAttribute && originScaleYAttribute)
    {
        sprite.setOriginFromScale({ originScaleXAttribute.as_float(), originScaleYAttribute.as_float() });
    }
    if (auto zOrderAttribute = spriteNode.attribute("zOrder"))
    {
        sprite.setZOrder(zOrderAttribute.as_int());
    }

    registry.assign<SpriteComponent>(entity, sprite);
}

void Parser::parseAnimation(entt::registry& registry, entt::entity entity, const pugi::xml_node& animationNode)
{
    AnimationComponent animation;

    registry.assign<AnimationComponent>(entity, animation);
}

void Parser::parsePosition(entt::registry& registry, entt::entity entity, const pugi::xml_node& positionNode)
{
    PositionComponent position;

    if (auto xAttribute = positionNode.attribute("x"))
    {
        position.setPosition({ xAttribute.as_float(), position.getPosition().y });
    }
    if (auto yAttribute = positionNode.attribute("y"))
    {
        position.setPosition({ position.getPosition().x, yAttribute.as_float() });
    }

    registry.assign<PositionComponent>(entity, position);
}

void Parser::parseRotation(entt::registry& registry, entt::entity entity, const pugi::xml_node& positionNode)
{
    RotationComponent rotation;

    if (auto angleAttribute = positionNode.attribute("angle"))
    {
        rotation.setAngle(angleAttribute.as_float());
    }

    registry.assign<RotationComponent>(entity, rotation);
}

void Parser::parseBody(entt::registry& registry, entt::dispatcher& dispatcher, entt::entity entity, const pugi::xml_node& bodyNode)
{
    BodyComponent body;

    auto bodyDef = Parser::parseBodyDef(bodyNode);

    std::vector<b2FixtureDef> fixtureDefs;
    std::vector<std::variant<b2CircleShape, b2EdgeShape, b2PolygonShape, b2ChainShape>> shapes;

    for (auto fixtureNode : bodyNode.children())
    {
        fixtureDefs.push_back(Parser::parseFixtureDef(fixtureNode));

        if (std::strcmp(fixtureNode.name(), "Circle") == 0)
        {
            shapes.push_back(Parser::parseCircle(fixtureNode));
        }
        else if (std::strcmp(fixtureNode.name(), "Edge") == 0)
        {
            shapes.push_back(Parser::parseEdge(fixtureNode));
        }
        else if (std::strcmp(fixtureNode.name(), "Polygon") == 0)
        {
            shapes.push_back(Parser::parsePolygon(fixtureNode));
        }
        else if (std::strcmp(fixtureNode.name(), "Chain") == 0)
        {
            shapes.push_back(Parser::parseChain(fixtureNode));
        }
    }

    registry.assign<BodyComponent>(entity, body);

    dispatcher.trigger(CreateBody{ entity, bodyDef, fixtureDefs, shapes });
}

void Parser::parseSpeed(entt::registry& registry, entt::entity entity, const pugi::xml_node& speedNode)
{
    SpeedComponent speed;

    if (auto linearSpeedAttribute = speedNode.attribute("linearSpeed"))
    {
        speed.setLinearSpeed(linearSpeedAttribute.as_float());
    }
    if (auto angularSpeedAttribute = speedNode.attribute("angularSpeed"))
    {
        speed.setAngularSpeed(angularSpeedAttribute.as_float());
    }

    registry.assign<SpeedComponent>(entity, speed);
}

void Parser::parseAcceleration(entt::registry& registry, entt::entity entity, const pugi::xml_node& accelerationNode)
{
    AccelerationComponent acceleration;

    if (auto linearAccelerationAttribute = accelerationNode.attribute("linearAcceleration"))
    {
        acceleration.setLinearAcceleration(linearAccelerationAttribute.as_float());
    }
    if (auto angularAccelerationAttribute = accelerationNode.attribute("angularAcceleration"))
    {
        acceleration.setAngularAcceleration(angularAccelerationAttribute.as_float());
    }

    registry.assign<AccelerationComponent>(entity, acceleration);
}

void Parser::parseObject(entt::registry& registry, entt::entity entity, const pugi::xml_node& objectNode)
{
    ObjectComponent object;

    auto objectType = magic_enum::enum_cast<ObjectType>(objectNode.text().as_string());

    if (objectType.has_value())
    {
        object.setObjectType(objectType.value());
    }

    registry.assign<ObjectComponent>(entity, object);
}