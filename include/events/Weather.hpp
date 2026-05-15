//
// Created by bartl on 15.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_WEATHER_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_WEATHER_HPP
#include <string>

class Weather {
private:
    std::string weather_Name;
    int modifyAttack;
    int modifyDefense;

public:
    int effect_on_Battle_Atc() const;
    int effect_on_Battle_Def() const;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_WEATHER_HPP