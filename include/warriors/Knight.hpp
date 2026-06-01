//
// Created by bartl on 13.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_KNIGHT_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_KNIGHT_HPP

#include <warriors/Warrior.hpp>

class Knight : public Warrior {
private:
    double atkBonus;
    double defBonus;

public:
    explicit Knight(const UnitStats& stats);


    void attack_Enemy(Warrior& enemy, double moraleModifier, WeatherType weather) override;
    void take_Damage(double damage) override;
    double get_WeatherModifier(WeatherType weather) const override;

    std::string get_Type() const override {
        return "Knight";
    }

};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_KNIGHT_HPP