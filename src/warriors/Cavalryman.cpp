//
// Created by bartl on 17.05.2026.
//

#include <warriors/Cavalryman.hpp>
#include <core/UnitStats.hpp>

// Cavalryman(medium unit) logic and attributes


Cavalryman::Cavalryman(const UnitStats& stats) :
    Warrior(stats),
    firstAttack(true),
    atkBonus(10),
    defBonus(5)
{}

void Cavalryman::attack_Enemy(Warrior& enemy, double moraleModifier, double effect_on_Battle_Atc) {

    int damage = (get_Attack()*moraleModifier*effect_on_Battle_Atc);

    if (firstAttack) {
        damage*=2;
        firstAttack=false;
    }

    enemy.take_Damage(damage);

}

void Cavalryman::take_Damage(double damage) {
    damage*=0.95;
    Warrior::take_Damage(damage);
};