//
// Created by bart on 11.05.2026.

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_CONFIGLOADER_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_CONFIGLOADER_HPP

// Declaration of class responsible for read config

#include <string>
#include "BattleConfig.hpp"


class ConfigLoader{
    public:
        static BattleConfig LoadFromFile(const std::string& filename);
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_CONFIGLOADER_HPP
