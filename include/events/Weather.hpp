//
// Created by bartl on 15.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_WEATHER_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_WEATHER_HPP

#include <string>
#include <events/WeatherType.hpp>


class Weather {
private:

    WeatherType weatherType;

    int modifyAttack;
    int modifyDefense;

public:

    Weather();

    WeatherType get_Weather() const;

    double effect_on_Battle_Atc() const;
    double effect_on_Battle_Def() const;

    std::string to_String() const;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_WEATHER_HPP