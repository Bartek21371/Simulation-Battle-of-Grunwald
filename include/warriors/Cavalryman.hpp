//
// Created by bartl on 13.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_CAVALRYMAN_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_CAVALRYMAN_HPP

#include <warriors/Warrior.hpp>

class Cavalryman : public Warrior {
private:
    bool firstAttack;
    int atkBonus;
    int defBonus;

public:
    explicit Cavalryman(const UnitStats& stats);

    void attack_Enemy(Warrior& enemy, double moraleModifier) override;
    void take_Damage(double damage) override;

};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_CAVALRYMAN_HPP