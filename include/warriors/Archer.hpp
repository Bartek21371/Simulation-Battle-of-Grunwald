//
// Created by bartl on 13.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_ARCHER_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_ARCHER_HPP

#include <warriors/warrior.hpp>

class Archer : public Warrior {
private:
    int atkBonus;
    int defBonus;

public:
    explicit Archer(const UnitStats& stats);

    //void take_Damage(double damage) override;

    //void attack_Enemy(Warrior& enemy) override;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_ARCHER_HPP