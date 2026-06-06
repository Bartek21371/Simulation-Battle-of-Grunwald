//
// Created by bart on 11.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_UNITSTATS_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_UNITSTATS_HPP

/**
 * @brief Holds base statistics shared by every warrior type.
 */
struct UnitStats {
    /// Initial hit points.
    int hp;
    /// Base attack value used when calculating damage.
    int attack;
    /// Base defense value used when reducing incoming damage.
    int defense;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_UNITSTATS_HPP
