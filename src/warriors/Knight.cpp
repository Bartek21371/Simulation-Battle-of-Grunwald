//
// Created by bartl on 17.05.2026.
//

#include <warriors/Knight.hpp>
#include <core/UnitStats.hpp>

// Knight(heavy unit) logic and attributes

Knight::Knight(const UnitStats& stats) :
    Warrior(stats),
    atkBonus(5),
    defBonus(10)
{}

double Knight::get_WeatherModifier(WeatherType weather) const {
    switch (weather) {
        case WeatherType::SUNNY:
            return 1.0;
        case WeatherType::RAINY:
            return 0.95;
        case WeatherType::FOGGY:
            return 0.9;
        case WeatherType::SNOWY:
            return 0.85;
    }
    return 1.0;

}


void Knight::attack_Enemy(Warrior& enemy, double moraleModifier, WeatherType weather) {
    double damage = (get_Attack()*moraleModifier*get_WeatherModifier(weather));
    damage *= (100.0 / (100.0+enemy.get_Defense()));

    enemy.take_Damage(damage);
}



void Knight::take_Damage(double damage) {
    damage *=0.8;
    Warrior::take_Damage(damage);
};