//
// Created by bart on 1.06.2026.
//

#include "events/AlliedHelp.hpp"
#include "utils/Random.hpp"

void AlliedHelp::apply(Army& army) {
    army.add_Reinforcements(Random::random_Int(10,500));
    army.increase_Morale(15);
}

std::string AlliedHelp::getName() const {
    return "Allied Reinforcement";
}