//
// Created by bart on 11.05.2026.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include <config/ConfigLoader.hpp>

bool is_config_valid(const FractionConfig& config);
bool is_integer(const std::vector<std::string>& str);
bool isnot_empty_string(const std::vector<std::string>& str);



// Implementation of loading params from csv file

std::vector<FractionConfig> ConfigLoader::LoadFromFile(const std::string& filename, bool printErrors = true) {
    std::vector<FractionConfig> configs;


    std::ifstream file_to_read(filename);
    std::string line;

    constexpr size_t EXPECTED_FIELDS = 13;

    // Handle error while opening file broken/unaccessed
    if (!file_to_read) {
        if (printErrors) {
            std::cerr << "Could not open file " << filename << "\n";
        }
    }


    // Skip header line
    std::getline(file_to_read, line);


    // Load each Fraction config
    while (std::getline(file_to_read, line)) {
        if (line.empty() || line[0] == '#') {
            continue;
        }

        FractionConfig config{};
        std::vector<std::string> values;

        std::stringstream ss(line);
        std::string value;


        // Get ready line with one fraction values
        while (getline(ss, value,',')) {
            values.push_back(value);
        }

        // Assignment of all corresponding values to fraction and catch errors
        if (values.size() == EXPECTED_FIELDS) {
            try {
                if (is_integer(values) && isnot_empty_string(values) ) {
                    config.fraction = values[0];

                    config.knight_stats.hp = std::stoi(values[1]);
                    config.knight_stats.attack = std::stoi(values[2]);
                    config.knight_stats.defense = std::stoi(values[3]);
                    config.knight_count = std::stoi(values[4]);

                    config.archer_stats.hp = std::stoi(values[5]);
                    config.archer_stats.attack = std::stoi(values[6]);
                    config.archer_stats.defense = std::stoi(values[7]);
                    config.archer_count = std::stoi(values[8]);


                    config.cavalry_stats.hp = std::stoi(values[9]);
                    config.cavalry_stats.attack = std::stoi(values[10]);
                    config.cavalry_stats.defense = std::stoi(values[11]);
                    config.cavalry_count = std::stoi(values[12]);

                    if (is_config_valid(config)) {
                        configs.push_back(config);
                    }
                    else {
                        config.valid = false;
                        configs.push_back(config);
                        if (printErrors) {
                            std::cout<<"Error, all values must be greater than zero" << "\n";
                        }
                    }
                }
                else {
                    config.valid = false;
                    configs.push_back(config);
                    if (printErrors) {
                        std::cout<<"Error, params of warriors must contain only digits and all values not be empty" << "\n";
                    }
                }
            }
            catch (const std::invalid_argument& e) {
                config.valid = false;
                configs.push_back(config);
                if (printErrors) {
                    std::cerr << "Error, value must be number" << e.what() << "\n";
                }
            }
            catch (const std::out_of_range& e) {
                config.valid = false;
                configs.push_back(config);
                if (printErrors) {
                    std::cerr << "Error, value out of range" << e.what() << "\n";
                }
            }
        }
        else {
            config.valid = false;
            configs.push_back(config);
            if (printErrors) {
                std::cerr << "Not enough values!" << filename << "\n";
            }
        }
    }

    return configs;
}

// Function for checking is all values is correct
// OPTIONAL SUGGEST add limit for count of types of warriors!
bool is_config_valid(const FractionConfig& config) {

    if (config.knight_stats.hp < 0 || config.knight_stats.attack < 0 || config.knight_stats.defense < 0) {
        return false;
    }
    if (config.archer_stats.hp < 0 || config.archer_stats.attack < 0 || config.archer_stats.defense < 0) {
        return false;
    }
    if (config.cavalry_stats.hp < 0 || config.cavalry_stats.attack < 0 || config.cavalry_stats.defense < 0) {
        return false;
    }
    if (config.knight_count < 0 || config.archer_count < 0 || config.cavalry_count < 0) {
        return false;
    }

    return true;
}


// Validate input is integer
bool is_integer(const std::vector<std::string>& str) {
    for (int i = 1; i<13;i++){
        for (char c : str[i]) {
            if (!std::isdigit(static_cast<unsigned char>(c))) {
                return false;
            }
        }
    }
    return true;
}

// Validate is input string not empty
bool isnot_empty_string(const std::vector<std::string>& str) {
    for (int i = 0; i<13;i++) {
        if (!str[i].empty()) {
            return false;
        }
    }
    return true;
}