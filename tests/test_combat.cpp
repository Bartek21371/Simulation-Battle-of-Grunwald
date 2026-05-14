//
// Created by bart on 14.05.2026.
//

#include <warriors/Warrior.hpp>
#include <config/ConfigLoader.hpp>
#include <core/UnitStats.hpp>

void test_combat() {
    std::vector<FractionConfig> config1 = ConfigLoader::LoadFromFile("../assets/configs/testfile.csv");


    Warrior warrior1 = Warrior(UnitStats config1[0]);
    Warrior warrior2 = Warrior(UnitStats config1[1]);
    warrior1.attack_Enemy(warrior2);
}