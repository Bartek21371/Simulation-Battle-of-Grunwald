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


bool Warrior::isAlive() {
    if (health <= 0) {
        alive = false;
    }
    else {
        alive = true;
    }
    return alive;
};

void Warrior::take_Damage(int damage) {
    health -= damage;
    isAlive();
};

void Warrior::attack_Enemy(Warrior& enemy) {
    enemy.take_Damage(attack);
};
