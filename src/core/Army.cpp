//
// Created by bartl on 14.05.2026.
//

#include <core/Army.hpp>

#include "warriors/Archer.hpp"
#include "warriors/Cavalryman.hpp"
#include "warriors/Knight.hpp"
#include "utils/Random.hpp"


Army::Army(FractionConfig config):
    name(config.fraction),attackBonus(0),defenseBonus(0),moraleLevel(0){


    if (!config.valid) {
        throw std::runtime_error("Invalid config");
    }

    for (int i = 0; i<config.knight_count; i++) {
        warriors.emplace_back(std::make_shared<Knight>(config.knight_stats));
    }

    for (int i = 0; i<config.archer_count; i++) {
        warriors.emplace_back(std::make_shared<Archer>(config.archer_stats));
    }

    for (int i = 0; i<config.cavalry_count; i++) {
        warriors.emplace_back(std::make_shared<Cavalryman>(config.cavalry_stats));
    }
}

int Army::get_ArmySize() const{
    return warriors.size();
}

const std::vector<std::shared_ptr<Warrior>>& Army::get_Warriors() const{
    return warriors;
}

int Army::count_AliveWarriors() const{
    int count = 0;
    for (const std::shared_ptr<Warrior>& w : warriors) {
        if (w->is_Alive()) {
            count++;
        }
    }
    return count;
}

Warrior& Army::get_RandomAliveWarrior() {
    std::vector<Warrior*> aliveWarriors;

    for (std::shared_ptr<Warrior>& w : warriors) {
        if (w->is_Alive()) {
            aliveWarriors.emplace_back(w.get());
        }
    }

    if (aliveWarriors.empty()) {
        throw std::runtime_error("No alive warrior");
    }

    int randomWarrior_id = Random::random_Int(0, static_cast<int>(aliveWarriors.size())-1);
    return *aliveWarriors[randomWarrior_id];
}