//
// Created by bart on 13.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_ARMY_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_ARMY_HPP
// vector<FractionConfig>
// Army army1(configs[0])...

#include <string>
#include <vector>

class Army {
private:

    std::string name;
    std::vector<Warrior> warriors;

    int attackBonus;
    int defenseBonus;
    int moraleLevel;


public:

    add_Warrior();

    remove_The_Fallen();

};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_ARMY_HPP
