//
// Created by bart on 13.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_ARMY_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_ARMY_HPP


// vector<FractionConfig>
// Army army1(configs[0])...

#include <string>
#include <vector>

#include <warriors/Warrior.hpp>
#include <config/FractionConfig.hpp>


/*enum class ArmyType {
    typeHussars,
    typeTeutonic
};*/

class Army {
private:

    std::string name;
    std::vector<Warrior> warriors;

    int attackBonus;
    int defenseBonus;
    int moraleLevel;


public:

    Army(FractionConfig config);

    int get_ArmySize();

    std::vector<Warrior>& get_Warriors();

    int count_AliveWarriors();

    /*void add_Warrior();

    void remove_The_Fallen();

    std::vector<Warrior>& get_Warriors();

    int get_attackBonus() const;
    int get_defenseBonus() const;
    int get_moraleLevel() const;*/

};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_ARMY_HPP
