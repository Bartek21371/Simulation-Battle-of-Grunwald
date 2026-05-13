//
// Created by bart on 13.05.2026.
//


#include <iostream>
#include <ostream>
#include <config/ConfigLoader.hpp>
#include <vector>

void test_loading_file() {
    std::vector<FractionConfig> config = ConfigLoader::LoadFromFile("../assets/configs/testfile.csv");
    std::cout<<config[0].fraction<<std::endl;
    std::cout<<config[0].knight.hp<<std::endl;
    std::cout<<config[0].knight.attack<<std::endl;
    std::cout<<config[0].knight.defense<<std::endl;
    std::cout<<config[1].fraction<<std::endl;
    std::cout<<config[1].knight.hp<<std::endl;
    std::cout<<config[1].knight.attack<<std::endl;
    std::cout<<config[1].knight.defense<<std::endl;
};

int main() {
    test_loading_file();
}