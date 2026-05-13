cmake_minimum_required(VERSION 4.2)
project(Simulation_Battle_of_Grunwald)

set(CMAKE_CXX_STANDARD 23)

#add_executable(Simulation_Battle_of_Grunwald main.cpp
    #src/core/Battle.cpp)



add_executable(Simulation_Battle_of_Grunwald main.cpp src/config/ConfigLoader.cpp)

add_executable(test_config tests/test_config.cpp src/config/ConfigLoader.cpp)

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