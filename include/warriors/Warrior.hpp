//
// Created by bartl on 13.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_WARRIOR_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_WARRIOR_HPP


#include <core/UnitStats.hpp>
#include <events/WeatherType.hpp>
#include <string>

/**
 * @brief Abstract base class for all battle units.
 */
class Warrior {
private:

    int health;
    int attack;
    int defense;

    bool alive;

public:

    /**
     * @brief Creates a warrior from base unit statistics.
     * @param stats Initial health, attack and defense values.
     */
    explicit Warrior(UnitStats);

    /// Enables safe destruction through a base pointer.
    virtual ~Warrior() = default;

    /**
     * @brief Applies damage and marks the warrior as dead when health reaches zero.
     * @param damage Raw damage value after attacker-side calculations.
     */
    virtual void take_Damage(double damage);

    /**
     * @brief Attacks another warrior.
     *
     * @param enemy Target warrior.
     * @param moraleModifier Army morale modifier used in damage calculations.
     * @param weather Current weather affecting unit effectiveness.
     */
    virtual void attack_Enemy(Warrior& enemy, double moraleModifier, WeatherType weather) = 0;

    /**
     * @brief Checks whether the warrior can still fight.
     */
    bool is_Alive() const;

    /**
     * @brief Returns unit-specific modifier for the given weather.
     */
    virtual double get_WeatherModifier(WeatherType weather) const=0;

    /**
     * @brief Returns a display name of the concrete warrior type.
     */
    virtual std::string get_Type() const = 0;

    /// Returns current health.
    int get_Health() const;

    /// Returns base attack value.
    int get_Attack() const;

    /// Returns base defense value.
    int get_Defense() const;
};


#endif //SIMULATION_BATTLE_OF_GRUNWALD_WARRIOR_HPP
