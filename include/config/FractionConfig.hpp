//
// Created by bart on 11.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_BATTLECONFIG_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_BATTLECONFIG_HPP

// Keep start parameters for one fraction

#include <core/UnitStats.hpp>
#include <string>

struct FractionConfig {
    std::string fraction;

    UnitStats knight_stats;
    int knight_count;

    UnitStats archer_stats;
    int archer_count;

    UnitStats cavalry_stats;
    int cavalry_count;

    bool valid = true;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_BATTLECONFIG_HPP
