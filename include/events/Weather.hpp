//
// Created by bartl on 15.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_WEATHER_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_WEATHER_HPP

#include <string>
#include <events/WeatherType.hpp>


/**
 * @brief Represents weather selected for one battle.
 */
class Weather {
private:

    WeatherType weatherType;

public:

    /**
     * @brief Creates a weather object with a randomly selected weather type.
     */
    Weather();

    /**
     * @brief Returns the selected weather type.
     */
    WeatherType get_Weather() const;

    /**
     * @brief Converts the selected weather type to text used in GUI and reports.
     */
    std::string to_String() const;

    /**
     * @brief Returns the selected weather type.
     */
    WeatherType get_WeatherType() const;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_WEATHER_HPP
