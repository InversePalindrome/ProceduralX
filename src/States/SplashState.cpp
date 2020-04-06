/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - States/SplashShate.cpp
https://inversepalindrome.com/
*/


#include "States/SplashState.hpp"


using namespace std::chrono_literals;

States::SplashState::SplashState(StateData& stateData) :
    State(stateData),
    splashScreen(stateData.resourceManager.getTexture(App::TextureID::SplashLogo)),
    splashTime(3s)
{
    splashScreen.setScale(0.3f, 0.3f);
    splashScreen.setOrigin(splashScreen.getLocalBounds().width / 2.f, splashScreen.getLocalBounds().height / 2.f);
    splashScreen.setPosition(stateData.window.getSize().x / 2.f, stateData.window.getSize().y / 2.f);
}

void States::SplashState::handleEvent(const sf::Event& event)
{

}

void States::SplashState::update(const App::Seconds& deltaTime)
{
    splashTime -= deltaTime;

    if (splashTime <= std::chrono::nanoseconds::zero())
    {
        stateData.eventDispatcher.dispatch(Events::EventID::ChangeState, StateID::Menu);
    }
}

void States::SplashState::render()
{
    stateData.window.draw(splashScreen);
}