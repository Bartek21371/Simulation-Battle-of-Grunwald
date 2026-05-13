//
// Created by bart on 11.05.2026.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include <config/ConfigLoader.hpp>

BattleConfig ConfigLoader::LoadFromFile(const std::string& filename) {
    BattleConfig config;


    std::ifstream file_to_read(filename);
    std::string line;
    if (!file_to_read) {
        std::cerr << "Could not open file " << filename << std::endl;
    }
    while (std::getline(file_to_read, line)) {
        std::cout<<line<<std::endl;
    }

    return config;
};