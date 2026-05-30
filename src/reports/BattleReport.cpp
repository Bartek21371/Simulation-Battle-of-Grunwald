//
// Created by bart on 25.05.2026.
//

#include <fstream>
#include <chrono>
#include <ctime>

#include "reports/BattleReport.hpp"

void BattleReport::save(const Battle& battle, const std::string& filename, int battleNumber) {
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::string date = std::ctime(&currentTime);
    date.pop_back();

    std::ofstream file;
    file.open(filename, std::ios::app);
    file<<battleNumber<<","
    <<battle.get_Winner()<<","
    <<battle.get_Rounds()<<","
    <<battle.get_HussarsArmy().count_AliveWarriors()<<","
    <<battle.get_TeutonicArmy().count_AliveWarriors()<<","
    <<battle.get_Stats().get_HussarsDamage_Dealt()<<","
    <<battle.get_Stats().get_TeutonicDamage_Dealt()<<","
    <<battle.get_Stats().get_HussarsKills()<<","
    <<battle.get_Stats().get_TeutonicKills()<<","
    <<battle.get_Weather()<<","
    <<"OK"<<","
    <<date<<"\n";
    file.close();
}

void BattleReport::save_skipped(const std::string& filename, int battleNumber, const std::string& reason) {
    std::ofstream file(filename, std::ios::app);

    file<<battleNumber<<","
    <<"SKIPPED"<<","
    <<"-"<<","
    <<"-"<<","
    <<"-"<<","
    <<"-"<<","
    <<"-"<<","
    <<"-"<<","
    <<"-"<<","
    <<"-"<<","
    <<reason<<","
    <<"-"<<"\n";
}
