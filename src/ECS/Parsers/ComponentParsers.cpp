/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Parsers/ComponentParsers.cpp
https://inversepalindrome.com/
*/


#include "ECS/Parsers/BodyParser.hpp"
#include "ECS/Parsers/JointParser.hpp"
#include "ECS/Parsers/ComponentParsers.hpp"

#include <thor/Animations/FrameAnimation.hpp>

#include <SFML/System/Time.hpp>

#include <magic_enum.hpp>

#include <vector>


void ECS::Parsers::parseID(Components::IDComponent& id, const pugi::xml_node& idNode)
{
    id.setID(idNode.text().as_uint());
}

void ECS::Parsers::parseSprite(Components::SpriteComponent& sprite, const pugi::xml_node& spriteNode, App::ResourceManager& resourceManager)
{
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
}

void ECS::Parsers::parseAnimation(Components::AnimationComponent& animation, const pugi::xml_node& animationNode)
{
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
}

void ECS::Parsers::parseSound(Components::SoundComponent& soundComponent, const pugi::xml_node& soundNode, App::ResourceManager& resourceManager)
{
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
}

void ECS::Parsers::parseTransform(Components::TransformComponent& transform, const pugi::xml_node& transformNode)
{
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
}

void ECS::Parsers::parseBody(Components::BodyComponent& body, const pugi::xml_node& bodyNode)
{
    b2BodyDef bodyDef;
    parseBodyDef(bodyDef, bodyNode);

    Components::BodyComponent::Fixtures fixtureDefs;
    Components::BodyComponent::Shapes shapes;

    for (auto fixtureNode : bodyNode.children())
    {
        b2FixtureDef fixtureDef;
        parseFixtureDef(fixtureDef, fixtureNode);
        fixtureDefs.push_back(fixtureDef);

        auto fixtureName = fixtureNode.name();

        if (std::strcmp(fixtureName, "Circle") == 0)
        {
            b2CircleShape circle;
            parseCircle(circle, fixtureNode);
            shapes.push_back(circle);
        }
        else if (std::strcmp(fixtureName, "Edge") == 0)
        {
            b2EdgeShape edge;
            parseEdge(edge, fixtureNode);
            shapes.push_back(edge);
        }
        else if (std::strcmp(fixtureName, "Polygon") == 0)
        {
            b2PolygonShape polygon;
            parsePolygon(polygon, fixtureNode);
            shapes.push_back(polygon);
        }
        else if (std::strcmp(fixtureName, "Chain") == 0)
        {
            b2ChainShape chain;
            parseChain(chain, fixtureNode);
            shapes.push_back(chain);
        }
    }

    body.setInitializationParameters(bodyDef, fixtureDefs, shapes);
}

void ECS::Parsers::parseJoint(Components::JointComponent& joint, const pugi::xml_node& jointNode)
{
    if (auto entityIDAAttribute = jointNode.attribute("entityIDA"))
    {
        joint.setEntityIDA(entityIDAAttribute.as_uint());
    }
    if (auto entityIDBAttribute = jointNode.attribute("entityIDB"))
    {
        joint.setEntityIDB(entityIDBAttribute.as_uint());
    }

    if (auto typeAttribute = jointNode.attribute("type"))
    {
        auto type = typeAttribute.as_string();

        Components::JointComponent::JointDefVariant jointDefVariant;

        if (std::strcmp(type, "Joint") == 0)
        {
            b2JointDef jointDef;
            parseJointDef(jointDef, jointNode);
            jointDefVariant = jointDef;
        }
        else if (std::strcmp(type, "DistanceJoint") == 0)
        {
            b2DistanceJointDef distanceJointDef;
            parseDistanceJointDef(distanceJointDef, jointNode);
            jointDefVariant = distanceJointDef;
        }
        else if (std::strcmp(type, "WeldJoint") == 0)
        {
            b2WeldJointDef weldJointDef;
            parseWeldJointDef(weldJointDef, jointNode);
            jointDefVariant = weldJointDef;
        }
        else if (std::strcmp(type, "RevoluteJoint") == 0)
        {
            b2RevoluteJointDef revoluteJointDef;
            parseRevoluteJointDef(revoluteJointDef, jointNode);
            jointDefVariant = revoluteJointDef;
        }
        else if (std::strcmp(type, "FrictionJoint") == 0)
        {
            b2FrictionJointDef frictionJointDef;
            parseFrictionJointDef(frictionJointDef, jointNode);
            jointDefVariant = frictionJointDef;
        }
        else if (std::strcmp(type, "PrismaticJoint") == 0)
        {
            b2PrismaticJointDef prismaticJointDef;
            parsePrismaticJointDef(prismaticJointDef, jointNode);
            jointDefVariant = prismaticJointDef;
        }
        else if (std::strcmp(type, "GearJoint") == 0)
        {
            b2GearJointDef gearJointDef;
            parseGearJointDef(gearJointDef, jointNode);
            jointDefVariant = gearJointDef;
        }
        else if (std::strcmp(type, "MotorJoint") == 0)
        {
            b2MotorJointDef motorJointDef;
            parseMotorJointDef(motorJointDef, jointNode);
            jointDefVariant = motorJointDef;
        }
        else if (std::strcmp(type, "MouseJoint") == 0)
        {
            b2MouseJointDef mouseJointDef;
            parseMouseJointDef(mouseJointDef, jointNode);
            jointDefVariant = mouseJointDef;
        }

        joint.setInitializationParameter(jointDefVariant);
    }
}

void ECS::Parsers::parseSpeed(Components::SpeedComponent& speed, const pugi::xml_node& speedNode)
{
    if (auto linearSpeedAttribute = speedNode.attribute("linearSpeed"))
    {
        speed.setLinearSpeed(linearSpeedAttribute.as_float());
    }
    if (auto angularSpeedAttribute = speedNode.attribute("angularSpeed"))
    {
        speed.setAngularSpeed(angularSpeedAttribute.as_float());
    }
}

void ECS::Parsers::parseAcceleration(Components::AccelerationComponent& acceleration, const pugi::xml_node& accelerationNode)
{
    if (auto linearAccelerationAttribute = accelerationNode.attribute("linearAcceleration"))
    {
        acceleration.setLinearAcceleration(linearAccelerationAttribute.as_float());
    }
    if (auto angularAccelerationAttribute = accelerationNode.attribute("angularAcceleration"))
    {
        acceleration.setAngularAcceleration(angularAccelerationAttribute.as_float());
    }
}

void ECS::Parsers::parseObject(Components::ObjectComponent& object, const pugi::xml_node& objectNode)
{
    auto objectTypeOptional = magic_enum::enum_cast<ObjectType>(objectNode.text().as_string());

    if (objectTypeOptional.has_value())
    {
        object.setObjectType(objectTypeOptional.value());
    }
}

void ECS::Parsers::parseState(Components::StateComponent& state, const pugi::xml_node& stateNode)
{
    auto entityStateOptional = magic_enum::enum_cast<State>(stateNode.text().as_string());

    if (entityStateOptional.has_value())
    {
        state.setState(entityStateOptional.value());
    }
}

void ECS::Parsers::parseWeapon(Components::WeaponComponent& weapon, const pugi::xml_node& weaponNode)
{
    auto entityOptional = magic_enum::enum_cast<EntityID>(weaponNode.text().as_string());

    if (entityOptional.has_value())
    {
        weapon.setProjectile(entityOptional.value());
    }

    if (auto reloadTimeAttribute = weaponNode.attribute("reloadTime"))
    {
        weapon.setReloadTime(App::Seconds(reloadTimeAttribute.as_float()));
    }
}

void ECS::Parsers::parseDamage(Components::DamageComponent& damage, const pugi::xml_node& damageNode)
{
    damage.setDamage(damageNode.text().as_float());
}

void ECS::Parsers::parseHealth(Components::HealthComponent& health, const pugi::xml_node& healthNode)
{
    health.setHealth(healthNode.text().as_float());
}

void ECS::Parsers::parseSatellite(Components::SatelliteComponent& satellite, const pugi::xml_node& satelliteNode)
{
    if (auto primaryEntityIDAttribute = satelliteNode.attribute("primaryEntityID"))
    {
        satellite.setPrimaryEntityID(primaryEntityIDAttribute.as_uint());
    }
    if (auto directionAttribute = satelliteNode.attribute("direction"))
    {
        auto directionOptional = magic_enum::enum_cast<RotationDirection>(directionAttribute.as_string());

        if (directionOptional.has_value())
        {
            satellite.setDirection(directionOptional.value());
        }
    }
}

void ECS::Parsers::parsePath(Components::PathComponent& path, const pugi::xml_node& pathNode)
{
    for (auto pointNode : pathNode.children("Point"))
    {
        if (auto xPositionAttribute = pointNode.attribute("x"),
            yPositionAttribute = pointNode.attribute("y");
            xPositionAttribute && yPositionAttribute)
        {
            path.addPoint({ xPositionAttribute.as_float(), yPositionAttribute.as_float() });
        }
    }
}