//
// Created by bartl on 31.05.2026.
//


#ifndef SIMULATION_BATTLE_OF_GRUNWALD_RANDOMEVENT_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_RANDOMEVENT_HPP

#include <core/Army.hpp>

class RandomEvent
{
public:
    virtual ~RandomEvent() = default;

    virtual void apply(Army& army) = 0;
    virtual std::string getName() const = 0;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_RANDOMEVENT_HPP
