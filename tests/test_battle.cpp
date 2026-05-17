//
// Created by bart on 16.05.2026.
//

#include <config/ConfigLoader.hpp>
#include <core/Battle.hpp>

// Test battle loop

void test_battle() {

    std::vector<FractionConfig> config1 = ConfigLoader::LoadFromFile("../assets/configs/testfile.csv");

    Army Hussars = Army(config1[0]);
    Army Teutonic = Army(config1[1]);

    Battle battle = Battle(Hussars,Teutonic);

    battle.start_Battle();
}


int main() {
    test_battle();
}