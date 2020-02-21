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