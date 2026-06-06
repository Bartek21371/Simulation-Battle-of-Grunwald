//
// Created by bartl on 13.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_KNIGHT_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_KNIGHT_HPP

#include <warriors/Warrior.hpp>

/**
 * @brief Heavy infantry unit with attack and defense bonuses.
 */
class Knight : public Warrior {
private:
    double atkBonus;
    double defBonus;

public:
    /**
     * @brief Creates a knight from base statistics.
     */
    explicit Knight(const UnitStats& stats);


    /// Performs a knight attack against another warrior.
    void attack_Enemy(Warrior& enemy, double moraleModifier, WeatherType weather) override;
    /// Applies incoming damage using knight defense behavior.
    void take_Damage(double damage) override;
    /// Returns knight-specific weather modifier.
    double get_WeatherModifier(WeatherType weather) const override;

    /// Returns "Knight".
    std::string get_Type() const override {
        return "Knight";
    }

};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_KNIGHT_HPP
