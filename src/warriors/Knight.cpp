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

void Knight::attack_Enemy(Warrior& enemy, double moraleModifier, double effect_on_Battle_Atc) {
    int damage = (get_Attack()*moraleModifier*effect_on_Battle_Atc);

    enemy.take_Damage(damage);
}

void Knight::take_Damage(double damage) {
    damage *=0.8;
    Warrior::take_Damage(damage);
};

