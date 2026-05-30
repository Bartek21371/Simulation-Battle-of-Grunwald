//
// Created by bartl on 13.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_ARCHER_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_ARCHER_HPP

#include <warriors/Warrior.hpp>

class Archer : public Warrior {
private:
    int atkBonus;
    int defBonus;

public:
    explicit Archer(const UnitStats& stats);

    void attack_Enemy(Warrior& enemy, double moraleModifier, WeatherType weather) override;
    void take_Damage(double damage) override;
    double get_WeatherModifier(WeatherType weather) const override;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_ARCHER_HPP