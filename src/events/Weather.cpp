//
// Created by bartl on 15.05.2026.
//

#include <events/Weather.hpp>


int Weather::effect_on_Battle_Atc() const {

    if (weather_Name == "SUNNY") return 10;
    if (weather_Name == "RAINY") return 11;
    if (weather_Name == "CLOUDY") return 12;
    if (weather_Name == "SNOWY") return 13;
    return 0;
}


int Weather::effect_on_Battle_Def() const {

    if (weather_Name == "SUNNY") return 3;
    if (weather_Name == "RAINY") return 4;
    if (weather_Name == "CLOUDY") return 5;
    if (weather_Name == "SNOWY") return 6;
    return 0;
}
