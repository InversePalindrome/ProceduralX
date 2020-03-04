/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - RenderSystem.cpp
https://inversepalindrome.com/
*/


#include "RenderSystem.hpp"
#include "ComponentTags.hpp"
#include "SizeConversions.hpp"
#include "RotationComponent.hpp"
#include "PositionComponent.hpp"
#include "PositionConversions.hpp"


RenderSystem::RenderSystem(entt::registry& registry, entt::dispatcher& dispatcher) :
    System(registry, dispatcher),
    playerEntity(entt::null),
    window(nullptr),
    map(nullptr)
{
    registry.on_construct<SpriteComponent>().connect<&RenderSystem::onSpriteAdded>(this);
    registry.on_construct<Player>().connect<&RenderSystem::onPlayerAdded>(this);
}

void RenderSystem::update(const Seconds& deltaTime)
{
    updateViewPosition();

    registry.view<SpriteComponent, PositionComponent, RotationComponent>().each(
        [](auto& sprite, const auto& position, const auto& rotation)
        {
            sprite.setPosition(Conversions::physicsToGraphicsPosition(position.getPosition()));
            sprite.setRotation(-rotation.getAngle());
        });
}

void RenderSystem::render()
{
    registry.view<SpriteComponent>().each([this](const auto& sprite)
        {
            window->draw(sprite);
        });
}

void RenderSystem::setWindow(sf::RenderWindow* window)
{
    this->window = window;

    cameraView = window->getDefaultView();
}

void RenderSystem::setMap(const Map* map)
{
    this->map = map;
}

void RenderSystem::updateViewPosition()
{
    auto cameraPosition = Conversions::physicsToGraphicsPosition(registry.get<PositionComponent>(playerEntity).getPosition());
    auto mapSize = Conversions::metersToPixelsSize({ map->getWidth(), map->getHeight() });
    auto cameraSize = cameraView.getSize();

    if (cameraPosition.x > mapSize.x - cameraSize.x / 2.f)
    {
        cameraPosition.x = mapSize.x - cameraSize.x / 2.f;
    }
    if (cameraPosition.x < cameraSize.x / 2.f)
    {
        cameraPosition.x = cameraSize.x / 2.f;
    }
    if (cameraPosition.y > mapSize.y - cameraSize.y / 2.f)
    {
        cameraPosition.y = mapSize.y - cameraSize.y / 2.f;
    }
    if (cameraPosition.y < cameraSize.y / 2.f)
    {
        cameraPosition.y = cameraSize.y / 2.f;
    }

    cameraView.setCenter(cameraPosition);
    
    window->setView(cameraView);
}

void RenderSystem::onSpriteAdded(entt::entity)
{
    registry.sort<SpriteComponent>([](const auto& lhs, const auto& rhs) { return lhs.getZOrder() < rhs.getZOrder(); });
}

void RenderSystem::onPlayerAdded(entt::entity entity)
{
    playerEntity = entity;
}