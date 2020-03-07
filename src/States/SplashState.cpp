/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - SplashShate.cpp
https://inversepalindrome.com/
*/


#include "States/SplashState.hpp"
#include "States/ChangeStateEvent.hpp"
#include "App/ResourceManager.hpp"


using namespace std::chrono_literals;

States::SplashState::SplashState(sf::RenderWindow& window, EventDispatcher& eventDispatcher) :
    State(window, eventDispatcher),
    splashScreen(App::ResourceManager::getInstance().getTexture(App::TextureID::SplashLogo)),
    splashTime(3s)
{
    splashScreen.setScale(0.3f, 0.3f);
    splashScreen.setOrigin(splashScreen.getLocalBounds().width / 2.f, splashScreen.getLocalBounds().height / 2.f);
    splashScreen.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
}

void States::SplashState::handleEvent(const sf::Event& event)
{

}

void States::SplashState::update(const App::Seconds& deltaTime)
{
    splashTime -= deltaTime;

    if (splashTime <= std::chrono::nanoseconds::zero())
    {
        eventDispatcher.dispatch(ChangeStateEvent(EventID::ChangeState, StateID::Game));
    }
}

void States::SplashState::render()
{
    window.draw(splashScreen);
}