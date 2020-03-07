/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - StateFactory.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "States/State.hpp"
#include "States/StateID.hpp"

#include <memory>
#include <functional>
#include <unordered_map>


namespace States
{
    using StatePtr = std::unique_ptr<State>;

    class StateFactory
    {
    public:
        StateFactory(sf::RenderWindow& window, EventDispatcher& eventDispatcher);

        StatePtr createState(StateID stateID);

    private:
        std::unordered_map<StateID, std::function<StatePtr()>> factory;
        sf::RenderWindow& window;
        EventDispatcher& eventDispatcher;

        template<typename T>
        void registerState(StateID stateID);
    };

    template<typename T>
    void StateFactory::registerState(StateID stateID)
    {
        factory[stateID] = [this]() { return std::make_unique<T>(window, eventDispatcher); };
    }
}