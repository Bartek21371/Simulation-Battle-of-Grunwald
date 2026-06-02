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

    Army(const FractionConfig& config);

    std::size_t get_ArmySize() const;

    const std::vector<std::shared_ptr<Warrior>>& get_Warriors() const;

    int count_AliveWarriors() const;

    int count_AliveKnights() const;
    int count_AliveArchers() const;
    int count_AliveCavalry() const;

    Warrior& get_RandomAliveWarrior();

    // Getter
    int get_moraleLevel() const;
    double get_MoraleModifier() const;
    const std::string& get_Name() const;

    // Setters
    void add_Reinforcements(int amount);
    void increase_Morale(int amount);
    void decrease_Morale(int amount);

};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_ARMY_HPP
