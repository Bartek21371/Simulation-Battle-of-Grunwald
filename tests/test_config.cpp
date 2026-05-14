//
// Created by bart on 13.05.2026.
//


#include <iostream>
#include <ostream>
#include <config/ConfigLoader.hpp>
#include <vector>

void test_loading_file() {
    std::vector<FractionConfig> config = ConfigLoader::LoadFromFile("../assets/configs/testfile.csv");
    for (int i=0; i<config.size(); i++) {
        std::cout<<"Name: "<<config[i].fraction<<std::endl;
        std::cout<<"Knight hp: "<<config[i].knight_stats.hp<<std::endl;
        std::cout<<"Knight attack: "<<config[i].knight_stats.attack<<std::endl;
        std::cout<<"Knight defense: "<<config[i].knight_stats.defense<<std::endl;
        std::cout<<"Knights count: "<<config[i].knight_count<<std::endl;
        std::cout<<"Is valid: "<<config[i].valid<<std::endl;
    }
};

int main() {
    test_loading_file();
}