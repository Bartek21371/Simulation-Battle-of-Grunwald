//
// Created by bart on 14.05.2026.
//

#include <warriors/Warrior.hpp>
#include <core/UnitStats.hpp>


// Abstract warrior class

Warrior::Warrior(UnitStats stats): health(stats.hp), attack(stats.attack), defense(stats.defense), alive(true)
{};


bool Warrior::is_Alive() const{
    return health>0;
};

void Warrior::take_Damage(const double damage) {
    health -= damage;
    if (health <= 0) health = 0;
};

// Getters

int Warrior::get_Health() const{
    return health;
};

int Warrior::get_Attack() const{
    return attack;
}

int Warrior::get_Defense() const {
    return defense;
}