//
// Created by bart on 11.05.2026.

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_CONFIGLOADER_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_CONFIGLOADER_HPP

// Declaration of class responsible for read config

#include <string>
#include <vector>
#include "FractionConfig.hpp"


class ConfigLoader{
    public:
        static std::vector<FractionConfig> LoadFromFile(const std::string& filename, bool printErrors);
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_CONFIGLOADER_HPP
