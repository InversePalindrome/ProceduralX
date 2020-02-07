/*
Copyright (c) 2020 Inverse Palindrome
ProceduralX - StateFactory.hpp
https://inversepalindrome.com/
*/


#pragma once

#include "State.hpp"
#include "StateID.hpp"

#include <memory>
#include <functional>
#include <unordered_map>


class StateFactory
{
    using StatePtr = std::unique_ptr<State>;

public:
    explicit StateFactory(sf::RenderWindow& window);

    StatePtr createState(StateID stateID);

private:
    std::unordered_map<StateID, std::function<StatePtr()>> factory;
    sf::RenderWindow& window;

    template<typename T>
    void registerState(StateID stateID);
};

template<typename T>
void StateFactory::registerState(StateID stateID)
{
    factory[stateID] = [this]() { return std::make_unique<T>(window); };
}