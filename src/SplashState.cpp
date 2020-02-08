/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SplashShate.cpp
https://inversepalindrome.com/
*/


#include "SplashState.hpp"

#include "ResourceManager.hpp"
#include "ChangeStateEvent.hpp"


using namespace std::chrono_literals;

SplashState::SplashState(sf::RenderWindow& window, EventDispatcher& eventDispatcher) :
    State(window, eventDispatcher),
    splashScreen(ResourceManager::getInstance().getTexture(TextureID::SplashLogo)),
    splashTime(2500ms)
{
    splashScreen.setScale(0.3f, 0.3f);
    splashScreen.setOrigin(splashScreen.getLocalBounds().width / 2.f, splashScreen.getLocalBounds().height / 2.f);
    splashScreen.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
}

void SplashState::handleEvent(const sf::Event& event)
{

}

void SplashState::update(const std::chrono::nanoseconds& deltaTime)
{
    splashTime -= deltaTime;

    if (splashTime <= std::chrono::nanoseconds::zero())
    {
        eventDispatcher.dispatch(ChangeStateEvent(EventID::ChangeState, StateID::Simulation));
    }
}

void SplashState::render()
{
    window.draw(splashScreen);
}