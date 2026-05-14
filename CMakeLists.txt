cmake_minimum_required(VERSION 4.2)
project(Simulation_Battle_of_Grunwald)

set(CMAKE_CXX_STANDARD 23)

add_executable(Simulation_Battle_of_Grunwald main.cpp
    src/core/Battle.cpp
        src/warriors/Warrior.cpp)
        #include/warriors/Warrior.hpp
        #include/warriors/Knight.hpp
        #include/warriors/Archer.hpp
        #include/warriors/Cavaleryman.hpp

add_executable(test_config tests/test_config.cpp src/config/ConfigLoader.cpp
        tests/test_combat.cpp)

add_executable(test_combat tests/test_combat.cpp warriors/Warrior.cpp)


target_include_directories(Simulation_Battle_of_Grunwald
        PUBLIC
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_SOURCE_DIR}/src
)

target_include_directories(test_config
        PUBLIC
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_SOURCE_DIR}/src
)

target_include_directories(test_combat
        PUBLIC
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_SOURCE_DIR}/src
)