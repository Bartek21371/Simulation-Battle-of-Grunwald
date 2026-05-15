//
// Created by bartl on 13.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_WARRIOR_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_WARRIOR_HPP

#include <iostream>
#include <core/UnitStats.hpp>

// Abstract class of warrior

class Warrior {
private:

    int health;
    int attack;
    int defense;

    bool alive;

public:

    Warrior(UnitStats);

    void take_Damage(double damage);

    bool is_Alive();

    void attack_Enemy(Warrior& enemy);

    // Getters

    int get_Health();

    int get_Attack();

    void set_Stats(UnitStats health);

};


#endif //SIMULATION_BATTLE_OF_GRUNWALD_WARRIOR_HPP