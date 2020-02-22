/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ComponentParsers.cpp
https://inversepalindrome.com/
*/


#include "ResourceManager.hpp"
#include "SpriteComponent.hpp"
#include "ComponentParsers.hpp"

#include <magic_enum.hpp>


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

ComponentVariant Parser::parseBody(entt::registry& registry, entt::entity entity, const pugi::xml_node& bodyNode)
{
    auto& body = registry.get_or_assign<BodyComponent>(entity);

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