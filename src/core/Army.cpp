//
// Created by bartl on 14.05.2026.
//


#include <core/Army.hpp>


Army::Army(FractionConfig config) {

    name = config.fraction;
    attackBonus = 0;
    defenseBonus = 0;
    moraleLevel = 0;

    for (int i = 0; i<config.knight_count; i++) {
        warriors.push_back(Warrior(config.knight_stats));
    }

    for (int i = 0; i<config.archer_count; i++) {
        warriors.push_back(Warrior(config.archer_stats));
    }

    for (int i = 0; i<config.cavalry_count; i++) {
        warriors.push_back(Warrior(config.cavalry_stats));
    }
}

int Army::get_ArmySize() {
    return warriors.size();
}

std::vector<Warrior>& Army::get_Warriors(){
    return warriors;
}

int Army::count_AliveWarriors() {
    int count = 0;
    for (Warrior& w : warriors) {
        if (w.is_Alive()) {
            count++;
        }
    }
    return count;
}