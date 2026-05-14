//
// Created by bart on 14.05.2026.
//

#include <warriors/Warrior.hpp>
#include <core/UnitStats.hpp>

Warrior::Warrior(UnitStats stats) {

    health = stats.hp;
    attack = stats.attack;
    defense = stats.defense;

    alive = true;
};


bool Warrior::is_Alive() {
    if (health <= 0) {
        alive = false;
    }
    else {
        alive = true;
    }
    return alive;
};

void Warrior::take_Damage(int damage) {
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!formula for calculate dammage!!!!!!!!!
    health -= damage;
    is_Alive();
};

void Warrior::attack_Enemy(Warrior& enemy) {
    enemy.take_Damage(attack);
};

int Warrior::get_Health() {
    return health;
};

int Warrior::get_Attack() {
    return attack;
}
