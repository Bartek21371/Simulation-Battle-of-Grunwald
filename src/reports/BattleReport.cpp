//
// Created by bart on 25.05.2026.
//

#include <fstream>

#include "reports/BattleReport.hpp"

void BattleReport::save(const Battle& battle, const std::string& filename, int battleNumber) {
    std::ofstream file;
    file.open(filename, std::ios::app);
    file<<battleNumber<<","<<battle.get_Winner()<<","<<battle.get_Rounds()<<","<<battle.get_HussarsArmy().count_AliveWarriors()<<","<<battle.get_TeutonicArmy().count_AliveWarriors()<<","<<"OK"<<"\n";
    file.close();
}

void BattleReport::save_skipped(const std::string& filename, int battleNumber, const std::string& reason) {
    std::ofstream file(filename, std::ios::app);

    file<<battleNumber<<","<<"SKIPPED"<<","<<"-"<<","<<"-"<<","<<"-"<<","<<reason<<"\n";
}
