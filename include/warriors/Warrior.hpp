//
// Created by bartl on 13.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_WARRIOR_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_WARRIOR_HPP

#include <iostream>
#include <core/UnitStats.hpp>

//

class Warrior {
private:

    int health;
    int attack;
    int defense;

    bool alive;

public:

    Warrior(UnitStats);

    int take_Damage();

    bool is_Alive();

    int attack_Enemy();

};


#endif //SIMULATION_BATTLE_OF_GRUNWALD_WARRIOR_HPP