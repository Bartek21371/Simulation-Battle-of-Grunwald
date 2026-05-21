//
// Created by bart on 15.05.2026.
//


#include <core/Army.hpp>
#include <config/ConfigLoader.hpp>
#include <catch2/catch_test_macros.hpp>


// Test creating army

TEST_CASE("Test creating two armies", "[army]") {
    auto configs = ConfigLoader::LoadFromFile("../assets/configs/testfile.csv", false);

    Army Hussars(configs[0]);
    Army Teutonic(configs[1]);

    SECTION("Check sizes of armies") {
        REQUIRE(Hussars.get_ArmySize()==135);
        REQUIRE(Teutonic.get_ArmySize()==155);
    }

    SECTION("Check is all warriors is alive after create") {
        REQUIRE(Hussars.count_AliveWarriors()==Hussars.get_ArmySize());
        REQUIRE(Teutonic.count_AliveWarriors()==Teutonic.get_ArmySize());
    }

    SECTION("Army contains warriors") {
        REQUIRE_FALSE(Hussars.get_Warriors().empty());
        REQUIRE_FALSE(Hussars.get_Warriors().empty());
    }

    SECTION("All warriors have health greater than 0") {
        for (auto& w : Hussars.get_Warriors()) {
            REQUIRE(w.get_Health()>0);
        }

        for (auto& w : Teutonic.get_Warriors()) {
            REQUIRE(w.get_Health()>0);
        }
    }
}