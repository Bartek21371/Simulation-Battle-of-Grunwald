cmake_minimum_required(VERSION 4.2)
project(Simulation_Battle_of_Grunwald)

set(CMAKE_CXX_STANDARD 23)

# Catch2
include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.15.0
)

FetchContent_MakeAvailable(Catch2)

# Main
add_executable(
        Simulation_Battle_of_Grunwald

        main.cpp
        src/core/Battle.cpp
        src/core/Army.cpp
        src/warriors/Warrior.cpp
        src/config/ConfigLoader.cpp
        include/reports/BattleReport.hpp
        src/reports/BattleReport.cpp

)

target_include_directories(
        Simulation_Battle_of_Grunwald
        PUBLIC
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_SOURCE_DIR}/src
)

#Tests
add_executable(
        tests

        tests/test_config.cpp
        tests/test_combat.cpp
        tests/test_army.cpp
        tests/test_battle.cpp

        src/core/Battle.cpp
        src/core/Army.cpp
        src/warriors/Warrior.cpp
        src/config/ConfigLoader.cpp
        tests/test_resultsave.cpp
)

target_include_directories(
        tests
        PUBLIC
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(
        tests
        PRIVATE Catch2::Catch2WithMain
)