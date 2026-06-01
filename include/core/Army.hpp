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

    int attackBonus;
    int defenseBonus;
    int moraleLevel;


public:

    Army(const FractionConfig& config);

    std::size_t get_ArmySize() const;

    const std::vector<std::shared_ptr<Warrior>>& get_Warriors() const;

    int count_AliveWarriors() const;

    Warrior& get_RandomAliveWarrior();

    double get_MoraleModifier() const;

    void increase_Morale(int amount);
    void decrease_Morale(int amount);

    // Getter
    int get_moraleLevel() const;

};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_ARMY_HPP
