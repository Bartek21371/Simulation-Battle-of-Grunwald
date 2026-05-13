//
// Created by bart on 11.05.2026.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include <config/ConfigLoader.hpp>

// Implementation of loading from csv file

std::vector<FractionConfig> ConfigLoader::LoadFromFile(const std::string& filename) {
    std::vector<FractionConfig> configs;


    std::ifstream file_to_read(filename);
    std::string line;

    // Handle error flags
    if (!file_to_read) {
        std::cerr << "Could not open file " << filename << std::endl;
    }


    // Skip header line
    std::getline(file_to_read, line);


    while (std::getline(file_to_read, line)) {
        if (line.empty() || line[0] == '#') {
            continue;
        }

        FractionConfig config;
        std::vector<std::string> values;

        std::stringstream ss(line);
        std::string value;

        while (getline(ss, value,',')) {
            values.push_back(value);
        }

        // Assignment of all corresponding values to fraction
        config.fraction = values[0];

        config.knight.hp = std::stoi(values[1]);
        config.knight.attack = std::stoi(values[2]);
        config.knight.defense = std::stoi(values[3]);

        config.archer.hp = std::stoi(values[4]);                // !!!!!! add validation is 9 values ?
        config.archer.attack = std::stoi(values[5]);
        config.archer.defense = std::stoi(values[6]);

        config.cavalry.hp = std::stoi(values[7]);
        config.cavalry.attack = std::stoi(values[8]);
        config.cavalry.defense = std::stoi(values[9]);

        configs.push_back(config);

    }

    return configs;
};