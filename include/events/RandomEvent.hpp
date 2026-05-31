//
// Created by bartl on 31.05.2026.
//


#ifndef SIMULATION_BATTLE_OF_GRUNWALD_RANDOMEVENT_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_RANDOMEVENT_HPP

#include <core/Army.hpp>

class RandomEvent {
public:

    RandomEvent();

    void activate(Army& army);

private:
    int activationChance; // 0-100

    bool commanderDeathHappened;
    bool alliedHelpHappened;
    bool panicHappened;

    static void commanderDeath(Army& army);
    static void alliedHelp(Army& army);
    static void panic(Army& army);
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_RANDOMEVENT_HPP
