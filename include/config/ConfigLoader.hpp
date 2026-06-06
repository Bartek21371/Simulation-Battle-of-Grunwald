//
// Created by bart on 11.05.2026.

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_CONFIGLOADER_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_CONFIGLOADER_HPP

#include <string>
#include <vector>
#include "FractionConfig.hpp"

/**
 * @brief Loads battle configuration rows from CSV files.
 */
class ConfigLoader{
    public:
        /**
         * @brief Reads fraction configurations from a CSV file.
         *
         * @param filename Path to the CSV configuration file.
         * @param printErrors If true, validation errors are printed to stderr/stdout.
         * @return Vector of loaded fraction configurations.
         */
        static std::vector<FractionConfig> LoadFromFile(const std::string& filename, bool printErrors);
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_CONFIGLOADER_HPP
