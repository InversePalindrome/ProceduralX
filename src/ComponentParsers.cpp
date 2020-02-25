/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ComponentParsers.cpp
https://inversepalindrome.com/
*/


#include "Events.hpp"
#include "BodyParser.hpp"
#include "ResourceManager.hpp"
#include "SpriteComponent.hpp"
#include "ComponentParsers.hpp"

#include <magic_enum.hpp>

#include <variant>


ComponentVariant Parser::parseSprite(entt::registry& registry, entt::entity entity, const pugi::xml_node& spriteNode)
{
    auto& sprite = registry.get_or_assign<SpriteComponent>(entity);

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

    return std::ref(sprite);
}

ComponentVariant Parser::parsePosition(entt::registry& registry, entt::entity entity, const pugi::xml_node& positionNode)
{
    auto& position = registry.get_or_assign<PositionComponent>(entity);

    if (auto xAttribute = positionNode.attribute("x"))
    {
        position.setPosition({ xAttribute.as_float(), position.getPosition().y });
    }
    if (auto yAttribute = positionNode.attribute("y"))
    {
        position.setPosition({ position.getPosition().x, yAttribute.as_float() });
    }

    return std::ref(position);
}

ComponentVariant Parser::parseRotation(entt::registry& registry, entt::entity entity, const pugi::xml_node& positionNode)
{
    auto& rotation = registry.get_or_assign<RotationComponent>(entity);

    if (auto angleAttribute = positionNode.attribute("angle"))
    {
        rotation.setAngle(angleAttribute.as_float());
    }

    return std::ref(rotation);
}

ComponentVariant Parser::parseBody(entt::registry& registry, entt::dispatcher& dispatcher, entt::entity entity, const pugi::xml_node& bodyNode)
{
    auto& body = registry.get_or_assign<BodyComponent>(entity);

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

    dispatcher.trigger(CreateBody{ body, bodyDef, fixtureDefs, shapes });

    return std::ref(body);
}

ComponentVariant Parser::parseSpeed(entt::registry& registry, entt::entity entity, const pugi::xml_node& speedNode)
{
    auto& speed = registry.get_or_assign<SpeedComponent>(entity);

    if (auto linearSpeedAttribute = speedNode.attribute("linearSpeed"))
    {
        speed.setLinearSpeed(linearSpeedAttribute.as_float());
    }
    if (auto angularSpeedAttribute = speedNode.attribute("angularSpeed"))
    {
        speed.setAngularSpeed(angularSpeedAttribute.as_float());
    }

    return std::ref(speed);
}

ComponentVariant Parser::parseAcceleration(entt::registry& registry, entt::entity entity, const pugi::xml_node& accelerationNode)
{
    auto& acceleration = registry.get_or_assign<AccelerationComponent>(entity);

    if (auto linearAccelerationAttribute = accelerationNode.attribute("linearAcceleration"))
    {
        acceleration.setLinearAcceleration(linearAccelerationAttribute.as_float());
    }
    if (auto angularAccelerationAttribute = accelerationNode.attribute("angularAcceleration"))
    {
        acceleration.setAngularAcceleration(angularAccelerationAttribute.as_float());
    }

    return std::ref(acceleration);
}