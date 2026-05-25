//
// Created by bart on 25.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_BATTLEREPORT_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_BATTLEREPORT_HPP

#include <string>
#include <core/Battle.hpp>

class BattleReport {
    public:
    static void save(const Battle& battle, const std::string& filename, int battleNumber);
    static void save_skipped(const std::string& filename, int battleNumber, const std::string& reason);
};



#endif //SIMULATION_BATTLE_OF_GRUNWALD_BATTLEREPORT_HPP
