//
// Created by bartl on 14.05.2026.
//

#include <core/Army.hpp>

#include "warriors/Archer.hpp"
#include "warriors/Cavalryman.hpp"
#include "warriors/Knight.hpp"
#include "utils/Random.hpp"


Army::Army(const FractionConfig& config):
    name(config.fraction),attackBonus(0),defenseBonus(0),moraleLevel(50),
    knightStats(config.knight_stats),
    archerStats(config.archer_stats),
    cavalryStats(config.cavalry_stats)
{


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

int Army::count_AliveWarriors() const{
    int count = 0;
    for (const std::shared_ptr<Warrior>& w : warriors) {
        if (w->is_Alive()) {
            count++;
        }
    }
    return count;
}

int Army::count_AliveKnights() const {
    int count{};

    for (const auto& w : warriors) {
        if (w->is_Alive() && dynamic_cast<Knight*>(w.get())) {
            count++;
        }
    }
    return count;
}

int Army::count_AliveArchers() const {
    int count{};

    for (const auto& w : warriors) {
        if (w->is_Alive() && dynamic_cast<Archer*>(w.get())) {
            count++;
        }
    }
    return count;
}

int Army::count_AliveCavalry() const {
    int count{};

    for (const auto& w : warriors) {
        if (w->is_Alive() && dynamic_cast<Cavalryman*>(w.get())) {
            count++;
        }
    }
    return count;
}

// Getters

size_t Army::get_ArmySize() const{
    return warriors.size();
}

const std::vector<std::shared_ptr<Warrior>>& Army::get_Warriors() const{
    return warriors;
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

// Setters

void Army::increase_Morale(int amount) {
    moraleLevel += amount;
    moraleLevel = std::min(moraleLevel,100);
}

void Army::decrease_Morale(int amount) {
    moraleLevel -= amount;
    moraleLevel = std::max(moraleLevel,0);
}


void Army::add_Reinforcements(int amount) {
    for(int i = 0; i < amount; i++){
        int type = Random::random_Int(0,2);

        switch(type){
            case 0:
                warriors.emplace_back(std::make_shared<Knight>(knightStats));
                break;
            case 1:
                warriors.emplace_back(std::make_shared<Archer>(archerStats));
                break;
            case 2:
                warriors.emplace_back(std::make_shared<Cavalryman>(cavalryStats));
                break;
        }
    }
}

// Getter

int Army::get_moraleLevel() const {
    return moraleLevel;
}

double Army::get_MoraleModifier() const {
    if (moraleLevel >= 70) {
        return 1.2;
    }
    if (moraleLevel <= 30) {
        return 0.8;
    }

    return 1.0;
}

const std::string& Army::get_Name() const {
    return name;
}
