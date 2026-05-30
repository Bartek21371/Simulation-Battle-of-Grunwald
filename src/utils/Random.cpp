//
// Created by bart on 28.05.2026.
//


#include <random>
#include <utils/Random.hpp>

// Util for random number

int Random::random_Int(int min, int max) {
    if (min > max) {
        throw std::out_of_range("min must be less than max");
    }

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> numberRange(min, max);

    return numberRange(gen);
}

