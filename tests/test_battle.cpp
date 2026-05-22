//
// Created by bart on 16.05.2026.
//

#include <config/ConfigLoader.hpp>
#include <core/Battle.hpp>
#include <catch2/catch_test_macros.hpp>


// Test battle loop

TEST_CASE("Test battle", "[battle]") {
    auto configs = ConfigLoader::LoadFromFile("../assets/configs/testfile.csv", false);

    Army Hussars(configs[0]);
    Army Teutonic(configs[1]);

    Battle battle(Hussars, Teutonic);

    battle.start_Battle();

    SECTION("Valid winner of battle") {
        auto winner = battle.get_Winner();

        REQUIRE_FALSE(winner.empty());
        REQUIRE( (winner == "Hussars" || winner == "Teutonic") );
    }
}