//
// Created by bart on 11.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_BATTLECONFIG_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_BATTLECONFIG_HPP

// Keep start parameters for one fraction

#include <core/UnitStats.hpp>

struct FractionConfig {
    UnitStats knight;
    UnitStats archer;
    UnitStats cavalry;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_BATTLECONFIG_HPP
