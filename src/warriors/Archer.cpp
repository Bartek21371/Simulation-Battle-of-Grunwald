//
// Created by bartl on 17.05.2026.
//

#include <warriors/Archer.hpp>
#include <core/UnitStats.hpp>
#include "utils/Random.hpp"

// Archer(light unit) logic and attributes


Archer::Archer(const UnitStats& stats) :
    Warrior(stats),
    atkBonus(1.25),
    defBonus(0.05)
{}

double Archer::get_WeatherModifier(WeatherType weather) const {
    switch (weather) {
        case WeatherType::SUNNY:
            return 1.0;
        case WeatherType::RAINY:
            return 0.75;
        case WeatherType::FOGGY:
            return 0.65;
        case WeatherType::SNOWY:
            return 0.85;
    }
    return 1.0;

}

void Archer::attack_Enemy(Warrior& enemy, double moraleModifier, WeatherType weather) {
    double damage = (get_Attack()*moraleModifier*get_WeatherModifier(weather)*atkBonus);
    damage *= (100.0 / (100.0+enemy.get_Defense()));

    enemy.take_Damage(damage);

    if (Random::random_Int(1, 100) <= 20) {
        enemy.take_Damage(damage);
    }

}

void Archer::take_Damage(double damage) {
    damage *= (1.0-defBonus);
    Warrior::take_Damage(damage);
};