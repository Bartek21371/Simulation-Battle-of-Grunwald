//
// Created by bartl on 17.05.2026.
//

#include <warriors/Cavalryman.hpp>
#include <core/UnitStats.hpp>

// Cavalryman(medium unit) logic and attributes


Cavalryman::Cavalryman(const UnitStats& stats) :
    Warrior(stats),
    firstAttack(true),
    atkBonus(1.15),
    defBonus(0.10)
{}

double Cavalryman::get_WeatherModifier(WeatherType weather) const {
    switch (weather) {
        case WeatherType::SUNNY:
            return 1.0;
        case WeatherType::RAINY:
            return 0.9;
        case WeatherType::FOGGY:
            return 0.85;
        case WeatherType::SNOWY:
            return 0.70;
    }
    return 1.0;

}

void Cavalryman::attack_Enemy(Warrior& enemy, double moraleModifier, WeatherType weather) {
    double damage = (get_Attack()*moraleModifier*get_WeatherModifier(weather)*atkBonus);
    damage *= (100.0 / (100.0+enemy.get_Defense()));

    if (firstAttack) {
        damage*=2;
        firstAttack=false;
    }

    enemy.take_Damage(damage);

}

void Cavalryman::take_Damage(double damage) {
    damage *= (1.0-defBonus);
    Warrior::take_Damage(damage);
};