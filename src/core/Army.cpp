//
// Created by bartl on 14.05.2026.
//

#include <random>
#include <core/Army.hpp>


Army::Army(FractionConfig config):
    name(config.fraction),attackBonus(0),defenseBonus(0),moraleLevel(0){


    if (!config.valid) {
        throw std::runtime_error("Invalid config");
    }

    for (int i = 0; i<config.knight_count; i++) {
        warriors.emplace_back(config.knight_stats);
    }

    for (int i = 0; i<config.archer_count; i++) {
        warriors.emplace_back(config.archer_stats);
    }

    for (int i = 0; i<config.cavalry_count; i++) {
        warriors.emplace_back(config.cavalry_stats);
    }
}

int Army::get_ArmySize() {
    return warriors.size();
}

std::vector<Warrior>& Army::get_Warriors(){
    return warriors;
}

int Army::count_AliveWarriors() const{
    int count = 0;
    for (const Warrior& w : warriors) {
        if (w.is_Alive()) {
            count++;
        }
    }
    return count;
}

Warrior& Army::get_RandomAliveWarrior() {
    std::vector<Warrior*> aliveWarriors;

    for (Warrior& w : warriors) {
        if (w.is_Alive()) {
            aliveWarriors.emplace_back(&w);
        }
    }

    if (aliveWarriors.empty()) {
        throw std::runtime_error("No alive warrior");
    }

    int randomWarrior_id = random_Number(0, static_cast<int>(aliveWarriors.size())-1);
    return *aliveWarriors[randomWarrior_id];
}


int Army::random_Number(int min, int max) {

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> numberRange(min, max);

    return numberRange(gen);
}