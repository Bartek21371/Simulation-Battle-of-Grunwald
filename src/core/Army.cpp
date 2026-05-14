//
// Created by bartl on 14.05.2026.
//

#include <core/Army.hpp>

/* to do
Army::Army(ArmyType type) {

    if (type == ArmyType::Hussars) {

    } else if (type == ArmyType::Teutonic) {

    }
}
*/


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
