/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - ECS/Serializers/ComponentSerializers.cpp
https://inversepalindrome.com/
*/


#include "ECS/Serializers/ComponentSerializers.hpp"
#include "ECS/Serializers/BodySerializer.hpp"

#include <magic_enum.hpp>


void ECS::Serializers::serializeSprite(const Components::SpriteComponent& sprite, pugi::xml_node& spriteNode)
{
    spriteNode.set_name("Sprite");

    auto textureRect = sprite.getTextureRect();

    spriteNode.append_attribute("texture") = std::string
    (magic_enum::enum_name(sprite.getTextureID())).c_str();

    spriteNode.append_attribute("textureLeft") = textureRect.left;
    spriteNode.append_attribute("textureTop") = textureRect.top;
    spriteNode.append_attribute("textureWidth") = textureRect.width;
    spriteNode.append_attribute("textureHeight") = textureRect.height;
    spriteNode.append_attribute("scaleX") = sprite.getScale().x;
    spriteNode.append_attribute("scaleY") = sprite.getScale().y;
    spriteNode.append_attribute("originScaleX") = sprite.getOriginScale().x;
    spriteNode.append_attribute("originScaleY") = sprite.getOriginScale().y;
    spriteNode.append_attribute("zOrder") = sprite.getZOrder();
}

void ECS::Serializers::serializeAnimation(const Components::AnimationComponent& animation, pugi::xml_node& animationNode)
{
    animationNode.set_name("Animation");

    for (const auto& [state, animationData] : animation)
    {
        auto frameAnimationNode = animationNode.append_child("FrameAnimation");
        
        frameAnimationNode.append_attribute("state") = std::string(magic_enum::enum_name(state)).c_str();
        frameAnimationNode.append_attribute("duration") = animationData.duration.count();
        frameAnimationNode.append_attribute("loop") = animationData.loop;
        
        for (const auto& frame : animationData.frames)
        {
            auto frameNode = frameAnimationNode.append_child("Frame");

            frameNode.append_attribute("duration") = frame.relativeDuration.count();
            frameNode.append_attribute("left") = frame.frameRect.left;
            frameNode.append_attribute("top") = frame.frameRect.top;
            frameNode.append_attribute("width") = frame.frameRect.width;
            frameNode.append_attribute("height") = frame.frameRect.height;
        }
    }
}

void ECS::Serializers::serializeSound(const Components::SoundComponent& sound, pugi::xml_node& soundNode)
{
    soundNode.set_name("Sound");

    for (const auto& [state, soundPair] : sound)
    {
        const auto& [soundID, soundItem] = soundPair;

        auto stateNode = soundNode.append_child(std::string(magic_enum::enum_name(state)).c_str());
        stateNode.text().set(std::string(magic_enum::enum_name(soundID)).c_str());

        stateNode.append_attribute("loop") = soundItem.getLoop();
        stateNode.append_attribute("pitch") = soundItem.getPitch();
        stateNode.append_attribute("volume") = soundItem.getVolume();
        stateNode.append_attribute("attenuation") = soundItem.getAttenuation();
        stateNode.append_attribute("minDistance") = soundItem.getMinDistance();
        stateNode.append_attribute("playingOffset") = soundItem.getPlayingOffset().asSeconds();
        stateNode.append_attribute("xPosition") = soundItem.getPosition().x;
        stateNode.append_attribute("zPosition") = soundItem.getPosition().z;
    }
}

void ECS::Serializers::serializeTransform(const Components::TransformComponent& transform, pugi::xml_node& transformNode)
{
    transformNode.set_name("Transform");

    transformNode.append_attribute("x") = transform.getPosition().x;
    transformNode.append_attribute("y") = transform.getPosition().y;
    transformNode.append_attribute("angle") = transform.getAngle();
}

void ECS::Serializers::serializeBody(const Components::BodyComponent& body, pugi::xml_node& bodyNode)
{
    bodyNode.set_name("Body");

    serializeBody(body.getBody(), bodyNode);

    for (const auto* fixture = body.getFixtureList(); fixture; fixture = fixture->GetNext())
    {
        auto fixtureNode = bodyNode.append_child();

        serializeFixture(fixture, fixtureNode);

        switch (fixture->GetType())
        {
        case b2Shape::e_circle:
            serializeCircle(static_cast<const b2CircleShape*>(fixture->GetShape()), fixtureNode);
            break;
        case b2Shape::e_edge:
            serializeEdge(static_cast<const b2EdgeShape*>(fixture->GetShape()), fixtureNode);
            break;
        case b2Shape::e_polygon:
            serializePolygon(static_cast<const b2PolygonShape*>(fixture->GetShape()), fixtureNode);
            break;
        case b2Shape::e_chain:
            serializeChain(static_cast<const b2ChainShape*>(fixture->GetShape()), fixtureNode);
            break;
        }
    }
}

void ECS::Serializers::serializeJoint(const Components::JointComponent& joint, pugi::xml_node& jointNode)
{
    jointNode.set_name("Joint");

    jointNode.append_attribute("entityA") = static_cast<std::size_t>(joint.getEntityA());
    jointNode.append_attribute("entityB") = static_cast<std::size_t>(joint.getEntityB());
}

void ECS::Serializers::serializeSpeed(const Components::SpeedComponent& speed, pugi::xml_node& speedNode)
{
    speedNode.set_name("Speed");

    speedNode.append_attribute("linearSpeed") = speed.getLinearSpeed();
    speedNode.append_attribute("angularSpeed") = speed.getAngularSpeed();
}

void ECS::Serializers::serializeAcceleration(const Components::AccelerationComponent& acceleration, pugi::xml_node& accelerationNode)
{
    accelerationNode.set_name("Acceleration");

    accelerationNode.append_attribute("linearAcceleration") = acceleration.getLinearAcceleration();
    accelerationNode.append_attribute("angularAcceleration") = acceleration.getAngularAcceleration();
}

void ECS::Serializers::serializeObject(const Components::ObjectComponent& object, pugi::xml_node& objectNode)
{
    objectNode.set_name("Object");

    objectNode.text().set(std::string(magic_enum::enum_name(object.getObjectType())).c_str());
}

void ECS::Serializers::serializeState(const Components::StateComponent& state, pugi::xml_node& stateNode)
{
    stateNode.set_name("State");

    stateNode.text().set(std::string(magic_enum::enum_name(state.getState())).c_str());
}

void ECS::Serializers::serializeWeapon(const Components::WeaponComponent& weapon, pugi::xml_node& weaponNode)
{
    weaponNode.set_name("Weapon");

    weaponNode.text().set(std::string(magic_enum::enum_name(weapon.getProjectile())).c_str());

    weaponNode.append_attribute("reloadTime") = weapon.getReloadTime().count();
}

void ECS::Serializers::serializeDamage(const Components::DamageComponent& damage, pugi::xml_node& damageNode)
{
    damageNode.set_name("Damage");

    damageNode.text().set(damage.getDamage());
}

void ECS::Serializers::serializeHealth(const Components::HealthComponent& health, pugi::xml_node& healthNode)
{
    healthNode.set_name("Health");

    healthNode.text().set(health.getHealth());
}