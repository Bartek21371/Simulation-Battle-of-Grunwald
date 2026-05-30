//
// Created by bartl on 15.05.2026.
//

#include <events/Weather.hpp>
#include <utils/Random.hpp>


Weather::Weather() {
    int weather = Random::random_Int(0, 3);

    switch (weather) {
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
    }
}

double Weather::effect_on_Battle_Atc() const {
    switch (weatherType) {
        case WeatherType::SUNNY:
            return 1.0;
        case WeatherType::RAINY:
            return 0.87;
        case WeatherType::FOGGY:
            return 0.5;
        case WeatherType::SNOWY:
            return 0.45;
    }
    return 1.0;

}


double Weather::effect_on_Battle_Def() const {
    switch (weatherType) {
        case WeatherType::SUNNY:
            return 1.0;
        case WeatherType::RAINY:
            return 0.95;
        case WeatherType::FOGGY:
            return 0.6;
        case WeatherType::SNOWY:
            return 0.8;
    }
    return 1.0;
}

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
    }

    return "UNKNOWN";
}