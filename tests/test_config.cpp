//
// Created by bart on 13.05.2026.
//


#include <iostream>
#include <ostream>
#include <config/ConfigLoader.hpp>
#include <vector>

// Test loading from file (checking errors,validate data,show data)

void test_loading_file() {
    std::vector<FractionConfig> config1 = ConfigLoader::LoadFromFile("../assets/configs/testfile.csv");

    for (size_t i=0; i<config1.size(); i++) {
        std::cout<<"Name: "<<config1[i].fraction<<"\n";
        std::cout<<"Knight hp: "<<config1[i].knight_stats.hp<<"\n";
        std::cout<<"Knight attack: "<<config1[i].knight_stats.attack<<"\n";
        std::cout<<"Knight defense: "<<config1[i].knight_stats.defense<<"\n";
        std::cout<<"Knights count: "<<config1[i].knight_count<<"\n";
        std::cout<<"Is valid: "<<config1[i].valid<<"\n";
        if (i%2==1) {
            std::cout<<"-------------------------------------------------------------------------"<<"\n";
        }
    }

    std::cout<<"|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<"\n";

    std::vector<FractionConfig> config2 = ConfigLoader::LoadFromFile("../assets/configs/testfile_5.csv");
    for (size_t i=0; i<config2.size(); i++) {
        std::cout<<"Name: "<<config2[i].fraction<<"\n";
        std::cout<<"Knight hp: "<<config2[i].knight_stats.hp<<"\n";
        std::cout<<"Knight attack: "<<config2[i].knight_stats.attack<<"\n";
        std::cout<<"Knight defense: "<<config2[i].knight_stats.defense<<"\n";
        std::cout<<"Knights count: "<<config2[i].knight_count<<"\n";
        std::cout<<"Is valid: "<<config2[i].valid<<"\n";
        if (i%2==1) {
            std::cout<<"-------------------------------------------------------------------------"<<"\n";
        }
    }



};

int main() {
    test_loading_file();
}