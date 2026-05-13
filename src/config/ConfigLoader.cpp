//
// Created by bart on 11.05.2026.
//

#include <iostream>
#include <fstream>
#include <ranges>
#include <sstream>
#include <vector>
#include <string>

#include <config/ConfigLoader.hpp>

// Implementation of loading from csv file

FractionConfig ConfigLoader::LoadFromFile(const std::string& filename) {
    FractionConfig config;


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

        std::vector<std::string> values;
        std::stringstream ss(line);
        std::string value;

        while (!ss.eof()) {
            getline(ss, value, ',');
            values.push_back(value);
        }
        for (std::string val : values) {
            std::cout<<val<<std::endl;
        }



    }

    return config;
};