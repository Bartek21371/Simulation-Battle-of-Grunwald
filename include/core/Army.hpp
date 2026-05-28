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


/*enum class ArmyType {
    typeHussars,
    typeTeutonic
};*/

class Army {
private:

    std::string name;
    std::vector<std::shared_ptr<Warrior>> warriors;

    int attackBonus;
    int defenseBonus;
    int moraleLevel;


public:

    Army(FractionConfig config);

    int get_ArmySize() const;

    const std::vector<std::shared_ptr<Warrior>>& get_Warriors() const;

    int count_AliveWarriors() const;

    Warrior& get_RandomAliveWarrior();

    /*
    int get_attackBonus() const;
    int get_defenseBonus() const;
    int get_moraleLevel() const;*/

};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_ARMY_HPP
