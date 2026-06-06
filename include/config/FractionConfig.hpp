//
// Created by bart on 11.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_BATTLECONFIG_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_BATTLECONFIG_HPP

#include <core/UnitStats.hpp>
#include <string>

/**
 * @brief Stores all starting parameters needed to create one army fraction.
 */
struct FractionConfig {
    /// Fraction name displayed in reports and GUI.
    std::string fraction;

    /// Base statistics for knights.
    UnitStats knight_stats;
    /// Number of knights created for the army.
    int knight_count;

    /// Base statistics for archers.
    UnitStats archer_stats;
    /// Number of archers created for the army.
    int archer_count;

    /// Base statistics for cavalrymen.
    UnitStats cavalry_stats;
    /// Number of cavalrymen created for the army.
    int cavalry_count;

    /// Indicates whether the row loaded from configuration passed validation.
    bool valid = true;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_BATTLECONFIG_HPP
