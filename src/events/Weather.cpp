//
// Created by bartl on 15.05.2026.
//

#include <events/Weather.hpp>
#include <utils/Random.hpp>


Weather::Weather() {

    switch (Random::random_Int(0, 3)) {
        case 0:
            weatherType = WeatherType::SUNNY;
            break;
        case 1:
            weatherType = WeatherType::RAINY;
            break;
        case 2:
            weatherType = WeatherType::FOGGY;
            break;
        case 3:
            weatherType = WeatherType::SNOWY;
            break;
        default:
            weatherType = WeatherType::SUNNY;
            break;
    }
}

// Get weather type for modify stats of each subclass warrior
WeatherType Weather::get_WeatherType() const {
    return weatherType;
}


// Switch to string for showing in program and saving result
std::string Weather::to_String() const {
    switch (weatherType) {
        case WeatherType::SUNNY:
            return "SUNNY";
        case WeatherType::RAINY:
            return "RAINY";
        case WeatherType::FOGGY:
            return "FOGGY";
        case WeatherType::SNOWY:
            return "SNOWY";
        default:
            return "UNKNOWN";
    }
}