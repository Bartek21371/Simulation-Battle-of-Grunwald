//
// Created by bart on 13.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_ARMY_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_ARMY_HPP


#include <string>
#include <vector>
#include <memory>

#include <warriors/Warrior.hpp>
#include <config/FractionConfig.hpp>


/**
 * @brief Represents one army taking part in a battle.
 *
 * Army owns a collection of warriors created from a fraction configuration and
 * tracks morale used during combat.
 */
class Army {
private:

    std::string name;
    std::vector<std::shared_ptr<Warrior>> warriors;

    UnitStats knightStats;
    UnitStats archerStats;
    UnitStats cavalryStats;

    int attackBonus;
    int defenseBonus;
    int moraleLevel;


public:

    /**
     * @brief Creates an army from loaded fraction configuration.
     * @throws std::runtime_error when the configuration is invalid.
     */
    Army(const FractionConfig& config);

    /// Returns total number of warriors in the army.
    std::size_t get_ArmySize() const;

    /// Returns all warriors belonging to the army.
    const std::vector<std::shared_ptr<Warrior>>& get_Warriors() const;

    /// Counts warriors that are still alive.
    int count_AliveWarriors() const;

    /// Counts living knights.
    int count_AliveKnights() const;
    /// Counts living archers.
    int count_AliveArchers() const;
    /// Counts living cavalrymen.
    int count_AliveCavalry() const;

    /**
     * @brief Selects a random living warrior.
     * @return Reference to selected warrior.
     */
    Warrior& get_RandomAliveWarrior();

    /// Returns current morale level.
    int get_moraleLevel() const;
    /// Returns morale modifier used in attack calculations.
    double get_MoraleModifier() const;
    /// Returns army name.
    const std::string& get_Name() const;

    /// Adds new warriors as reinforcements.
    void add_Reinforcements(int amount);
    /// Increases morale by the given amount.
    void increase_Morale(int amount);
    /// Decreases morale by the given amount.
    void decrease_Morale(int amount);

};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_ARMY_HPP
