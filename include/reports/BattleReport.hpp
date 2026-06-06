//
// Created by bart on 25.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_BATTLEREPORT_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_BATTLEREPORT_HPP

#include <string>
#include <core/Battle.hpp>

/**
 * @brief Writes battle results to CSV report files.
 */
class BattleReport {
    public:
    /**
     * @brief Appends a completed battle result to a CSV report.
     */
    static void save(const Battle& battle, const std::string& filename, int battleNumber);
    /**
     * @brief Appends information about a skipped battle to a CSV report.
     */
    static void save_skipped(const std::string& filename, int battleNumber, const std::string& reason);
};



#endif //SIMULATION_BATTLE_OF_GRUNWALD_BATTLEREPORT_HPP
