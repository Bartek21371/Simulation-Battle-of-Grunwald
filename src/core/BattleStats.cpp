//
// Created by bart on 30.05.2026.
//


#include "core/BattleStats.hpp"

void BattleStats::add_HussarsDamage(double damage) {
    HussarsDamage_Dealt+=damage;
}

void BattleStats::add_TeutonicDamage(double damage) {
    TeutonicDamage_Dealt+=damage;
}


void BattleStats::add_HussarsKill() {
    HussarsKills+=1;
}

void BattleStats::add_TeutonicKill() {
    TeutonicKills+=1;
}


// Getters

double BattleStats::get_HussarsDamage_Dealt() const {
    return HussarsDamage_Dealt;
}

double BattleStats::get_TeutonicDamage_Dealt() const {
    return TeutonicDamage_Dealt;
}


int BattleStats::get_HussarsKills() const {
    return HussarsKills;
}

int BattleStats::get_TeutonicKills() const {
    return TeutonicKills;
}


