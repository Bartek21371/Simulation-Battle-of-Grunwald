//
// Created by bart on 14.05.2026.
//

#include <warriors/Knight.hpp>
#include <config/ConfigLoader.hpp>
#include <catch2/catch_test_macros.hpp>


// Test combat of warrior1 on warrior 2

//NEED FIX

TEST_CASE("Attack reduces enemy health", "[combat]") {
    auto configs = ConfigLoader::LoadFromFile("../assets/configs/testfile.csv", false);

    Knight attacker(configs[0].knight_stats);
    Knight defender(configs[1].knight_stats);

    auto initialHealth = defender.get_Health();

    attacker.attack_Enemy(defender, 1.0, WeatherType::SUNNY);

    REQUIRE(defender.get_Health() < initialHealth);

}

TEST_CASE("Warrior dies after enough attacks", "[combat]") {
    auto configs = ConfigLoader::LoadFromFile("../assets/configs/testfile.csv", false);

    Knight attacker(configs[0].knight_stats);
    Knight defender(configs[1].knight_stats);

    int attacks{};

    while (defender.is_Alive() && attacks < 5000) {
        attacker.attack_Enemy(defender, 1.0, WeatherType::SUNNY);

        attacks++;
    }

    REQUIRE_FALSE(defender.is_Alive());
    REQUIRE(defender.get_Health() <= 0);

}