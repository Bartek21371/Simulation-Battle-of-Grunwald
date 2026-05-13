//
// Created by bart on 13.05.2026.
//

#include <config/ConfigLoader.hpp>

int main() {
    FractionConfig config = ConfigLoader::LoadFromFile("../assets/configs/testfile.csv");
}