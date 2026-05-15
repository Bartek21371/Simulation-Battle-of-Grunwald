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

void Army::get_ArmySize() {
    std::cout<<"Army size: "<<warriors.size()<<"\n";
}