/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Parsers/ComponentParsers.cpp
https://inversepalindrome.com/
*/


#include "ECS/Parsers/BodyParser.hpp"
#include "ECS/Parsers/ComponentParsers.hpp"
#include "App/ResourceManager.hpp"

#include <thor/Animations/FrameAnimation.hpp>

#include <SFML/System/Time.hpp>

#include <magic_enum.hpp>

#include <vector>


ECS::Components::SpriteComponent ECS::Parsers::parseSprite(const pugi::xml_node& spriteNode, App::ResourceManager& resourceManager)
{
    Components::SpriteComponent sprite;

    if (auto textureAttribute = spriteNode.attribute("texture"))
    {
        auto textureID = magic_enum::enum_cast<App::TextureID>(textureAttribute.as_string());
 
        if (textureID.has_value())
        {
            sprite.setTextureID(textureID.value());
            sprite.setTexture(resourceManager.getTexture(textureID.value()));
        }
    }
    if (auto textureLeftAttribute = spriteNode.attribute("textureLeft"),
        textureTopAttribute = spriteNode.attribute("textureTop"),
        textureWidthAttribute = spriteNode.attribute("textureWidth"),
        textureHeightAttribute = spriteNode.attribute("textureHeight");
        textureLeftAttribute && textureTopAttribute && textureWidthAttribute && textureHeightAttribute)
    {
        sprite.setTextureRect({ textureLeftAttribute.as_int(), textureTopAttribute.as_int(),
            textureWidthAttribute.as_int(), textureHeightAttribute.as_int() });
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
        sprite.setOriginScale({ originScaleXAttribute.as_float(), originScaleYAttribute.as_float() });
    }
    if (auto zOrderAttribute = spriteNode.attribute("zOrder"))
    {
        sprite.setZOrder(zOrderAttribute.as_int());
    }

    return sprite;
}

ECS::Components::AnimationComponent ECS::Parsers::parseAnimation(const pugi::xml_node& animationNode)
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

        thor::FrameAnimation frameAnimation;
        std::vector<FrameData> frames;
  
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
            frames.push_back({ App::Seconds(relativeDuration), frameRect });
        }

        animation.addAnimation(state, frameAnimation, { frames, App::Seconds(duration.asSeconds()), loop});
    }

    return animation;
}

ECS::Components::SoundComponent ECS::Parsers::parseSound(const pugi::xml_node& soundNode, App::ResourceManager& resourceManager)
{
    Components::SoundComponent soundComponent;

    for (auto stateNode : soundNode.children())
    {
        auto stateOptional = magic_enum::enum_cast<State>(stateNode.name());
        auto soundOptional = magic_enum::enum_cast<App::SoundID>(stateNode.text().as_string());

        if (stateOptional.has_value() && soundOptional.has_value())
        {
            sf::Sound sound(resourceManager.getSoundBuffer(soundOptional.value()));

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
            if (auto playingOffsetAttribute = stateNode.attribute("playingOffset"))
            {
                sound.setPlayingOffset(sf::seconds(playingOffsetAttribute.as_float()));
            }
            if (auto xPositionAttribute = stateNode.attribute("xPosition"),
                zPositionAttribute = stateNode.attribute("zPosition");
                xPositionAttribute && zPositionAttribute)
            {
                sound.setPosition(xPositionAttribute.as_float(), 0.f, zPositionAttribute.as_float());
            }

            soundComponent.addSound(stateOptional.value(), soundOptional.value(), sound);
        }
    }

    return soundComponent;
}

ECS::Components::TransformComponent ECS::Parsers::parseTransform(const pugi::xml_node& transformNode)
{
    Components::TransformComponent transform;

    if (auto xAttribute = transformNode.attribute("x"))
    {
        transform.setPosition({ xAttribute.as_float(), transform.getPosition().y });
    }
    if (auto yAttribute = transformNode.attribute("y"))
    {
        transform.setPosition({ transform.getPosition().x, yAttribute.as_float() });
    }
    if (auto angleAttribute = transformNode.attribute("angle"))
    {
        transform.setAngle(angleAttribute.as_float());
    }

    return transform;
}

ECS::Components::BodyComponent ECS::Parsers::parseBody(const pugi::xml_node& bodyNode)
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

    return body;
}

ECS::Components::SpeedComponent ECS::Parsers::parseSpeed(const pugi::xml_node& speedNode)
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

    return speed;
}

ECS::Components::AccelerationComponent ECS::Parsers::parseAcceleration(const pugi::xml_node& accelerationNode)
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

    return acceleration;
}

ECS::Components::ObjectComponent ECS::Parsers::parseObject(const pugi::xml_node& objectNode)
{
    Components::ObjectComponent object;

    auto objectTypeOptional = magic_enum::enum_cast<ObjectType>(objectNode.text().as_string());

    if (objectTypeOptional.has_value())
    {
        object.setObjectType(objectTypeOptional.value());
    }

    return object;
}

ECS::Components::StateComponent ECS::Parsers::parseState(const pugi::xml_node& stateNode)
{
    Components::StateComponent state;

    auto entityStateOptional = magic_enum::enum_cast<State>(stateNode.text().as_string());

    if (entityStateOptional.has_value())
    {
        state.setState(entityStateOptional.value());
    }

    return state;
}

ECS::Components::WeaponComponent ECS::Parsers::parseWeapon(const pugi::xml_node& weaponNode)
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

    return weapon;
}

ECS::Components::DamageComponent ECS::Parsers::parseDamage(const pugi::xml_node& damageNode)
{
    Components::DamageComponent damage;

    damage.setDamage(damageNode.text().as_float());

    return damage;
}

ECS::Components::HealthComponent ECS::Parsers::parseHealth(const pugi::xml_node& healthNode)
{
    Components::HealthComponent health;

    health.setHealth(healthNode.text().as_float());

    return health;
}