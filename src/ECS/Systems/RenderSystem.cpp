/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - RenderSystem.cpp
https://inversepalindrome.com/
*/


#include "ECS/Systems/RenderSystem.hpp"
#include "ECS/Components/ComponentTags.hpp"
#include "ECS/Components/RotationComponent.hpp"
#include "ECS/Components/PositionComponent.hpp"
#include "ECS/Utility/PositionConversions.hpp"
#include "ECS/Utility/SizeConversions.hpp"


ECS::Systems::RenderSystem::RenderSystem(entt::registry& registry, entt::dispatcher& dispatcher,
    EntityFactory& entityFactory) :
    System(registry, dispatcher, entityFactory),
    playerEntity(entt::null),
    window(nullptr),
    map(200.f, 200.f)
{
    registry.on_construct<Components::SpriteComponent>().connect<&RenderSystem::onSpriteAdded>(this);
    registry.on_construct<Components::Player>().connect<&RenderSystem::onPlayerAdded>(this);
}

void ECS::Systems::RenderSystem::update(const App::Seconds& deltaTime)
{
    updateViewPosition();

    registry.view<Components::SpriteComponent, Components::PositionComponent, Components::RotationComponent>().each(
        [](auto& sprite, const auto& position, const auto& rotation)
        {
            sprite.setPosition(Utility::physicsToGraphicsPosition(position.getPosition()));
            sprite.setRotation(-rotation.getAngle());
        });
}

void ECS::Systems::RenderSystem::render()
{
    registry.view<Components::SpriteComponent>().each([this](const auto& sprite)
        {
            window->draw(sprite);
        });
}

void ECS::Systems::RenderSystem::setWindow(sf::RenderWindow* window)
{
    this->window = window;

    cameraView = window->getDefaultView();
}

void ECS::Systems::RenderSystem::updateViewPosition()
{
    auto cameraPosition = Utility::physicsToGraphicsPosition(registry.get<Components::
        PositionComponent>(playerEntity).getPosition());
    auto mapSize = Utility::metersToPixelsSize({ map.getWidth(), map.getHeight() });
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

void ECS::Systems::RenderSystem::onSpriteAdded(entt::entity)
{
    registry.sort<Components::SpriteComponent>([](const auto& lhs, const auto& rhs) 
        { return lhs.getZOrder() < rhs.getZOrder(); });
}

void ECS::Systems::RenderSystem::onPlayerAdded(entt::entity entity)
{
    playerEntity = entity;
}