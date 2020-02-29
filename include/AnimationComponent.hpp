/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - AnimationComponent.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "AnimationID.hpp"

#include <Thor/Animations/Animator.hpp>
#include <Thor/Animations/FrameAnimation.hpp>

#include <SFML/Graphics/Sprite.hpp>


class AnimationComponent
{
public:


private:
    thor::Animator<sf::Sprite, AnimationID> animator;
};