cmake_minimum_required(VERSION 4.2)
project(Simulation_Battle_of_Grunwald)

set(CMAKE_CXX_STANDARD 23)

add_executable(Simulation_Battle_of_Grunwald main.cpp
        src/core/Battle.cpp)

target_include_directories(Simulation_Battle_of_Grunwald
        PUBLIC
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/assets
)