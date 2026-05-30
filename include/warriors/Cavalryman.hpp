//
// Created by bartl on 13.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_CAVALRYMAN_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_CAVALRYMAN_HPP

#include <warriors/Warrior.hpp>

class Cavalryman : public Warrior {
private:
    bool firstAttack;
    double atkBonus;
    double defBonus;

public:
    explicit Cavalryman(const UnitStats& stats);

    void attack_Enemy(Warrior& enemy, double moraleModifier, WeatherType weather) override;
    void take_Damage(double damage) override;
    double get_WeatherModifier(WeatherType weather) const override;

};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_CAVALRYMAN_HPP