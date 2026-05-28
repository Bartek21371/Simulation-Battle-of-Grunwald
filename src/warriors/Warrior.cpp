//
// Created by bart on 14.05.2026.
//

#include <warriors/Warrior.hpp>
#include <core/UnitStats.hpp>


// ADD INITALIZER LIST
// Make pure virtual for get abstract class

Warrior::Warrior(UnitStats stats) {

    health = stats.hp;
    attack = stats.attack;
    defense = stats.defense;

    alive = true;
};


bool Warrior::is_Alive() const{
    return health>0;
};

void Warrior::take_Damage(const double damage) {
    health -= damage;
    if (health <= 0) health = 0;
};

// !!! ADD MORE EXTENDED VERSIO OF CALC DAMAGE (COUNT OF KNIGHTS ETC...)

void Warrior::attack_Enemy(Warrior& enemy, double moraleModifier) {
    double calc_final_damage = attack*(100.0/(100.0+enemy.defense));
    enemy.take_Damage(calc_final_damage);
};

int Warrior::get_Health() const{
    return health;
};

int Warrior::get_Attack() const{
    return attack;
}
