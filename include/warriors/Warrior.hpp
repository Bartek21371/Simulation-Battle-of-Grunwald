//
// Created by bartl on 13.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_WARRIOR_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_WARRIOR_HPP

#include <iostream>
#include <core/UnitStats.hpp>
#include <events/WeatherType.hpp>

// Abstract class of warrior

class Warrior {
private:

    int health;
    int attack;
    int defense;

    bool alive;

public:

    explicit Warrior(UnitStats);

    virtual ~Warrior() = default;

    virtual void take_Damage(double damage);

    virtual void attack_Enemy(Warrior& enemy, double moraleModifier, WeatherType weather) = 0;

    bool is_Alive() const;

    virtual double get_WeatherModifier(WeatherType weather) const=0;

    // Getters
    int get_Health() const;

    int get_Attack() const;

    int get_Defense() const;
};


#endif //SIMULATION_BATTLE_OF_GRUNWALD_WARRIOR_HPP