//
// Created by bart on 13.05.2026.
//


#include <iostream>
#include <ostream>
#include <config/ConfigLoader.hpp>
#include <vector>
#include <catch2/catch_test_macros.hpp>

// Test loading from file (checking errors,validate data)

TEST_CASE("Loading from file correctly") {
    auto configs = ConfigLoader::LoadFromFile("../assets/configs/testfile.csv", false);

    REQUIRE(configs.size()==2);

    SECTION("First fraction loaded correctly", "[config]") {

        REQUIRE(configs[0].knight_stats.hp==66);
        REQUIRE(configs[0].knight_stats.attack==40);
        REQUIRE(configs[0].knight_stats.defense==20);

        REQUIRE(configs[0].knight_count==50);

        REQUIRE(configs[0].archer_stats.hp==80);
        REQUIRE(configs[0].archer_stats.attack==45);
        REQUIRE(configs[0].archer_stats.defense==10);

        REQUIRE(configs[0].archer_count==45);

        REQUIRE(configs[0].cavalry_stats.hp==100);
        REQUIRE(configs[0].cavalry_stats.attack==25);
        REQUIRE(configs[0].cavalry_stats.defense==60);

        REQUIRE(configs[0].cavalry_count==40);

        REQUIRE(configs[0].valid);
    }

    SECTION("Second fraction loaded correctly") {

        REQUIRE(configs[1].knight_stats.hp==90);
        REQUIRE(configs[1].knight_stats.attack==35);
        REQUIRE(configs[1].knight_stats.defense==25);

        REQUIRE(configs[1].knight_count==80);

        REQUIRE(configs[1].archer_stats.hp==50);
        REQUIRE(configs[1].archer_stats.attack==50);
        REQUIRE(configs[1].archer_stats.defense==10);

        REQUIRE(configs[1].archer_count==20);

        REQUIRE(configs[1].cavalry_stats.hp==80);
        REQUIRE(configs[1].cavalry_stats.attack==25);
        REQUIRE(configs[1].cavalry_stats.defense==55);

        REQUIRE(configs[1].cavalry_count==55);

        REQUIRE(configs[1].valid);
    }

}

TEST_CASE("Loading from file and detect errors", "[config]") {
    auto configs = ConfigLoader::LoadFromFile("../assets/configs/testfile_5.csv", false);

    REQUIRE(configs.size()==10);

    SECTION("No enough values") {
        REQUIRE_FALSE(configs[0].valid);
    }

    SECTION("Value lower than 0") {
        REQUIRE_FALSE(configs[2].valid);
    }

    SECTION("Value out of range") {
        REQUIRE_FALSE(configs[1].valid);
    }

    SECTION("Value contains number with letters") {
        REQUIRE_FALSE(configs[6].valid);
    }

    SECTION("Value contain only letters") {
        REQUIRE_FALSE(configs[9].valid);
    }

    SECTION("Value is empty string") {
        REQUIRE_FALSE(configs[3].valid);
    }
}