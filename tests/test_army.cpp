//
// Created by bart on 15.05.2026.
//


#include <core/Army.hpp>
#include <config/ConfigLoader.hpp>

// Test creating army

void test_army() {

    std::vector<FractionConfig> config1 = ConfigLoader::LoadFromFile("../assets/configs/testfile.csv");

    Army Hussars = Army(config1[0]);
    Army Teutonic = Army(config1[1]);
    Hussars.get_ArmySize();
    Teutonic.get_ArmySize();
}

int main() {
    test_army();
}