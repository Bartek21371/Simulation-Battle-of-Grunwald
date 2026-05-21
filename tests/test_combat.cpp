//
// Created by bart on 14.05.2026.
//

#include <warriors/Warrior.hpp>
#include <config/ConfigLoader.hpp>
#include <catch2/catch_test_macros.hpp>


// Test combat of warrior1 on warrior 2

TEST_CASE("Attack reduces enemy health", "[combat]") {
    auto configs = ConfigLoader::LoadFromFile("../assets/configs/testfile.csv", false);

    Warrior warrior1(configs[0].knight_stats);
    Warrior warrior2(configs[1].knight_stats);

    int initialHealth = warrior2.get_Health();

    warrior1.attack_Enemy(warrior2);

    REQUIRE(warrior2.get_Health() < initialHealth);

}

TEST_CASE("Warrior dies after enough attacks", "[combat]") {
    auto configs = ConfigLoader::LoadFromFile("../assets/configs/testfile.csv", false);

    Warrior warrior1(configs[0].knight_stats);
    Warrior warrior2(configs[1].knight_stats);

    while (warrior2.is_Alive()) {
        warrior1.attack_Enemy(warrior2);
    }

    REQUIRE_FALSE(warrior2.is_Alive());
    REQUIRE(warrior2.get_Health() <= 0);

}