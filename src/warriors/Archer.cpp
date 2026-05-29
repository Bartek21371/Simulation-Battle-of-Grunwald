//
// Created by bartl on 17.05.2026.
//

#include <warriors/Archer.hpp>
#include <core/UnitStats.hpp>
#include "utils/Random.hpp"

// Archer(light unit) logic and attributes


Archer::Archer(const UnitStats& stats) :
    Warrior(stats),
    atkBonus(15),
    defBonus(0)
{}

void Archer::attack_Enemy(Warrior& enemy, double moraleModifier, double effect_on_Battle_Atc) {
    int damage = (get_Attack()*moraleModifier*effect_on_Battle_Atc);
    enemy.take_Damage(damage);

    if (Random::random_Int(1, 100) <= 20) {
        enemy.take_Damage(damage);
    }

}

void Archer::take_Damage(double damage) {
    damage*=1.2;
    Warrior::take_Damage(damage);
};