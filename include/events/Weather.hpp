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

    std::string to_String() const;

    // Getter
    WeatherType get_WeatherType() const;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_WEATHER_HPP