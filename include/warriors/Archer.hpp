//
// Created by bartl on 13.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_ARCHER_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_ARCHER_HPP

#include <warriors/Warrior.hpp>

/**
 * @brief Ranged unit with weather-sensitive attack effectiveness.
 */
class Archer : public Warrior {
private:
    double atkBonus;
    double defBonus;

public:
    /**
     * @brief Creates an archer from base statistics.
     */
    explicit Archer(const UnitStats& stats);

    /// Performs an archer attack against another warrior.
    void attack_Enemy(Warrior& enemy, double moraleModifier, WeatherType weather) override;
    /// Applies incoming damage using archer defense behavior.
    void take_Damage(double damage) override;
    /// Returns archer-specific weather modifier.
    double get_WeatherModifier(WeatherType weather) const override;

    /// Returns "Archer".
    std::string get_Type() const override {
        return "Archer";
    }

};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_ARCHER_HPP
