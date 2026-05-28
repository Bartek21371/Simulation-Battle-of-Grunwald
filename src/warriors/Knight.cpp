//
// Created by bartl on 17.05.2026.
//

#include <warriors/Knight.hpp>
#include <core/UnitStats.hpp>

Knight::Knight(const UnitStats& stats) :
    Warrior(stats),
    atkBonus(5),
    defBonus(10)
{}

void Knight::attack_Enemy(Warrior& enemy) {
    enemy.take_Damage(get_Attack());
}

/*
void Archer::take_Damage(double damage) {
    health -= (damage);
    if (health <= 0) health = 0;
};


void Archer::attack_Enemy(Warrior& enemy) {
    double calc_final_damage = attack*(100.0/(100.0+enemy.defense));
    enemy.take_Damage(calc_final_damage);
};
*/