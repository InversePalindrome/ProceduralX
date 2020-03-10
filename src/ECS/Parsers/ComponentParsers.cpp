/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ComponentParsers.cpp
https://inversepalindrome.com/
*/


#include "ECS/Parsers/BodyParser.hpp"
#include "ECS/Parsers/ComponentParsers.hpp"
#include "ECS/Components/BodyComponent.hpp"
#include "ECS/Components/SpeedComponent.hpp"
#include "ECS/Components/StateComponent.hpp"
#include "ECS/Components/SoundComponent.hpp"
#include "ECS/Components/SpriteComponent.hpp"
#include "ECS/Components/ObjectComponent.hpp"
#include "ECS/Components/WeaponComponent.hpp"
#include "ECS/Components/DamageComponent.hpp"
#include "ECS/Components/HealthComponent.hpp"
#include "ECS/Components/AnimationComponent.hpp"
#include "ECS/Components/AccelerationComponent.hpp"
#include "ECS/Components/PositionComponent.hpp"
#include "ECS/Components/RotationComponent.hpp"
#include "App/ResourceManager.hpp"

#include <thor/Animations/FrameAnimation.hpp>

#include <SFML/System/Time.hpp>

#include <magic_enum.hpp>


void ECS::Parsers::parseSprite(entt::registry& registry, entt::entity entity, const pugi::xml_node& spriteNode)
{
    Components::SpriteComponent sprite;

    if (auto textureAttribute = spriteNode.attribute("texture"))
    {
        auto textureID = magic_enum::enum_cast<App::TextureID>(textureAttribute.as_string());
 
        if (textureID.has_value())
        {
            sprite.setTexture(App::ResourceManager::getInstance().getTexture(textureID.value()));
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

    registry.assign<Components::SpriteComponent>(entity, sprite);
}

void ECS::Parsers::parseAnimation(entt::registry& registry, entt::entity entity, const pugi::xml_node& animationNode)
{
    Components::AnimationComponent animation;

    for (auto frameAnimationNode : animationNode.children("FrameAnimation"))
    {
        auto state = State::Idle;

        if (auto stateAttribute = frameAnimationNode.attribute("state"))
        {
            auto stateIDOptional = magic_enum::enum_cast<State>(stateAttribute.as_string());

            if (stateIDOptional.has_value())
            {
                state = stateIDOptional.value();
            }
        }

        thor::FrameAnimation frameAnimation;
  
        for (auto frameNode : frameAnimationNode.children("Frame"))
        {
            float relativeDuration = 1.f;

            if (auto durationAttribute = frameNode.attribute("duration"))
            {
                relativeDuration = durationAttribute.as_float();
            }

            sf::IntRect frameRect;

            if (auto leftAttribute = frameNode.attribute("left"),
                topAttribute = frameNode.attribute("top"),
                widthAttribute = frameNode.attribute("width"),
                heightAttribute = frameNode.attribute("height");
                leftAttribute && topAttribute && widthAttribute && heightAttribute)
            {
                frameRect = { leftAttribute.as_int(), topAttribute.as_int(),
                    widthAttribute.as_int(), heightAttribute.as_int() };
            }

            frameAnimation.addFrame(relativeDuration, frameRect);
        }

        sf::Time duration = sf::seconds(1.f);

        if (auto durationAttribute = frameAnimationNode.attribute("duration"))
        {
            duration = sf::seconds(durationAttribute.as_float());
        }

        bool loop = false;

        if (auto loopAttribute = frameAnimationNode.attribute("loop"))
        {
            loop = loopAttribute.as_bool();
        }

        animation.addAnimation(state, frameAnimation, duration, loop);
    }

    registry.assign<Components::AnimationComponent>(entity, animation);
}

void ECS::Parsers::parseSound(entt::registry& registry, entt::entity entity, const pugi::xml_node& soundNode)
{
    Components::SoundComponent soundComponent;

    for (auto stateNode : soundNode.children())
    {
        auto stateOptional = magic_enum::enum_cast<State>(stateNode.name());
        auto soundOptional = magic_enum::enum_cast<App::SoundID>(stateNode.text().as_string());

        if (stateOptional.has_value() && soundOptional.has_value())
        {
            sf::Sound sound(App::ResourceManager::getInstance().getSoundBuffer(soundOptional.value()));

            if (auto loopAttribute = stateNode.attribute("loop"))
            {
                sound.setLoop(loopAttribute.as_bool());
            }
            if (auto pitchAttribute = stateNode.attribute("pitch"))
            {
                sound.setPitch(pitchAttribute.as_float());
            }
            if (auto volumeAttribute = stateNode.attribute("volume"))
            {
                sound.setVolume(volumeAttribute.as_float());
            }
            if (auto attenuationAttribute = stateNode.attribute("attenuation"))
            {
                sound.setAttenuation(attenuationAttribute.as_float());
            }
            if (auto minDistanceAttribute = stateNode.attribute("minDistance"))
            {
                sound.setMinDistance(minDistanceAttribute.as_float());
            }
            if (auto timeOffsetAttribute = stateNode.attribute("timeOffset"))
            {
                sound.setPlayingOffset(sf::seconds(timeOffsetAttribute.as_float()));
            }
            if (auto xPositionAttribute = stateNode.attribute("xPosition"),
                zPositionAttribute = stateNode.attribute("zPosition");
                xPositionAttribute && zPositionAttribute)
            {
                sound.setPosition(xPositionAttribute.as_float(), 0.f, zPositionAttribute.as_float());
            }

            soundComponent.addSound(stateOptional.value(), sound);
        }
    }

    registry.assign<Components::SoundComponent>(entity, soundComponent);
}

void ECS::Parsers::parsePosition(entt::registry& registry, entt::entity entity, const pugi::xml_node& positionNode)
{
    Components::PositionComponent position;

    if (auto xAttribute = positionNode.attribute("x"))
    {
        position.setPosition({ xAttribute.as_float(), position.getPosition().y });
    }
    if (auto yAttribute = positionNode.attribute("y"))
    {
        position.setPosition({ position.getPosition().x, yAttribute.as_float() });
    }

    registry.assign<Components::PositionComponent>(entity, position);
}

void ECS::Parsers::parseRotation(entt::registry& registry, entt::entity entity, const pugi::xml_node& positionNode)
{
    Components::RotationComponent rotation;

    if (auto angleAttribute = positionNode.attribute("angle"))
    {
        rotation.setAngle(angleAttribute.as_float());
    }

    registry.assign<Components::RotationComponent>(entity, rotation);
}

void ECS::Parsers::parseBody(entt::registry& registry, entt::entity entity, const pugi::xml_node& bodyNode)
{
    Components::BodyComponent body;

    auto bodyDef = parseBodyDef(bodyNode);

    Components::BodyComponent::Fixtures fixtureDefs;
    Components::BodyComponent::Shapes shapes;

    for (auto fixtureNode : bodyNode.children())
    {
        fixtureDefs.push_back(parseFixtureDef(fixtureNode));

        if (std::strcmp(fixtureNode.name(), "Circle") == 0)
        {
            shapes.push_back(parseCircle(fixtureNode));
        }
        else if (std::strcmp(fixtureNode.name(), "Edge") == 0)
        {
            shapes.push_back(parseEdge(fixtureNode));
        }
        else if (std::strcmp(fixtureNode.name(), "Polygon") == 0)
        {
            shapes.push_back(parsePolygon(fixtureNode));
        }
        else if (std::strcmp(fixtureNode.name(), "Chain") == 0)
        {
            shapes.push_back(parseChain(fixtureNode));
        }
    }

    body.setInitializationParameters(bodyDef, fixtureDefs, shapes);
    registry.assign<Components::BodyComponent>(entity, body);
}

void ECS::Parsers::parseSpeed(entt::registry& registry, entt::entity entity, const pugi::xml_node& speedNode)
{
    Components::SpeedComponent speed;

    if (auto linearSpeedAttribute = speedNode.attribute("linearSpeed"))
    {
        speed.setLinearSpeed(linearSpeedAttribute.as_float());
    }
    if (auto angularSpeedAttribute = speedNode.attribute("angularSpeed"))
    {
        speed.setAngularSpeed(angularSpeedAttribute.as_float());
    }

    registry.assign<Components::SpeedComponent>(entity, speed);
}

void ECS::Parsers::parseAcceleration(entt::registry& registry, entt::entity entity, const pugi::xml_node& accelerationNode)
{
    Components::AccelerationComponent acceleration;

    if (auto linearAccelerationAttribute = accelerationNode.attribute("linearAcceleration"))
    {
        acceleration.setLinearAcceleration(linearAccelerationAttribute.as_float());
    }
    if (auto angularAccelerationAttribute = accelerationNode.attribute("angularAcceleration"))
    {
        acceleration.setAngularAcceleration(angularAccelerationAttribute.as_float());
    }

    registry.assign<Components::AccelerationComponent>(entity, acceleration);
}

void ECS::Parsers::parseObject(entt::registry& registry, entt::entity entity, const pugi::xml_node& objectNode)
{
    Components::ObjectComponent object;

    auto objectTypeOptional = magic_enum::enum_cast<ObjectType>(objectNode.text().as_string());

    if (objectTypeOptional.has_value())
    {
        object.setObjectType(objectTypeOptional.value());
    }

    registry.assign<Components::ObjectComponent>(entity, object);
}

void ECS::Parsers::parseState(entt::registry& registry, entt::entity entity, const pugi::xml_node& stateNode)
{
    Components::StateComponent state;

    auto entityStateOptional = magic_enum::enum_cast<State>(stateNode.text().as_string());

    if (entityStateOptional.has_value())
    {
        state.setState(entityStateOptional.value());
    }

    registry.assign<Components::StateComponent>(entity, state);
}

void ECS::Parsers::parseWeapon(entt::registry& registry, entt::entity entity, const pugi::xml_node& weaponNode)
{
    Components::WeaponComponent weapon;

    auto entityOptional = magic_enum::enum_cast<EntityID>(weaponNode.text().as_string());

    if (entityOptional.has_value())
    {
        weapon.setProjectile(entityOptional.value());
    }

    if (auto reloadTimeAttribute = weaponNode.attribute("reloadTime"))
    {
        weapon.setReloadTime(App::Seconds(reloadTimeAttribute.as_float()));
    }

    registry.assign<Components::WeaponComponent>(entity, weapon);
}

void ECS::Parsers::parseDamage(entt::registry& registry, entt::entity entity, const pugi::xml_node& damageNode)
{
    Components::DamageComponent damage;

    damage.setDamage(damageNode.text().as_float());

    registry.assign<Components::DamageComponent>(entity, damage);
}

void ECS::Parsers::parseHealth(entt::registry& registry, entt::entity entity, const pugi::xml_node& healthNode)
{
    Components::HealthComponent health;

    health.setHealth(healthNode.text().as_float());

    registry.assign<Components::HealthComponent>(entity, health);
}