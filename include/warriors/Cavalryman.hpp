//
// Created by bartl on 13.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_CAVALRYMAN_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_CAVALRYMAN_HPP

#include <warriors/Warrior.hpp>

/**
 * @brief Mounted unit with a stronger first attack.
 */
class Cavalryman : public Warrior {
private:
    bool firstAttack;
    double atkBonus;
    double defBonus;

public:
    /**
     * @brief Creates a cavalryman from base statistics.
     */
    explicit Cavalryman(const UnitStats& stats);

    /// Performs a cavalry attack against another warrior.
    void attack_Enemy(Warrior& enemy, double moraleModifier, WeatherType weather) override;
    /// Applies incoming damage using cavalry defense behavior.
    void take_Damage(double damage) override;
    /// Returns cavalry-specific weather modifier.
    double get_WeatherModifier(WeatherType weather) const override;

    /// Returns "Cavalryman".
    std::string get_Type() const override {
        return "Cavalryman";
    }

};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_CAVALRYMAN_HPP
