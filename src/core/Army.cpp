//
// Created by bartl on 14.05.2026.
//

#include <core/Army.hpp>

#include "config/FractionConfig.hpp"


Army::Army() {



    std::vector<FractionConfig> config1 = ConfigLoader::LoadFromFile("../assets/configs/testfile.csv");;


}



void Army::add_Warrior() {
    warriors.push_back()
}

std::vector<Warrior>& Army::get_Warriors() {
    return warriors;
}

int Army::get_attackBonus() const {
    return attackBonus;
}

int Army::get_defenseBonus() const {
    return defenseBonus;
}

int Army::get_moraleLevel() const {
    return moraleLevel;
}
