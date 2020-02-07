/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SplashShate.cpp
https://inversepalindrome.com/
*/


#include "SplashState.hpp"

#include "ResourceManager.hpp"


SplashState::SplashState(sf::RenderWindow& window) :
    State(window),
    splashScreen(ResourceManager::getInstance().getTexture(TextureID::SplashLogo))
{
    splashScreen.setScale(0.3f, 0.3f);
    splashScreen.setOrigin(splashScreen.getLocalBounds().width / 2.f, splashScreen.getLocalBounds().height / 2.f);
    splashScreen.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
}

void SplashState::handleEvent(const sf::Event& event)
{

}

void SplashState::update(const std::chrono::milliseconds& deltaTime)
{

}

void SplashState::render()
{
    window.draw(splashScreen);
}