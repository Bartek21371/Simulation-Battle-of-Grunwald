//
// Created by bart on 28.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_RANDOM_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_RANDOM_HPP

/**
 * @brief Utility wrapper for generating random integer values.
 */
class Random {
public:
    /**
     * @brief Returns a random integer from the inclusive range [min, max].
     */
    static int random_Int(int min, int max);
};



#endif //SIMULATION_BATTLE_OF_GRUNWALD_RANDOM_HPP
