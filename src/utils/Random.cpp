//
// Created by bart on 28.05.2026.
//


#include <random>
#include <utils/Random.hpp>

// Util for random number

int Random::random_Int(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> numberRange(min, max);

    return numberRange(gen);
}

