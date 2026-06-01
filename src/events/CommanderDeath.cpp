//
// Created by bart on 1.06.2026.
//

#include <events/CommanderDeath.hpp>

void CommanderDeath::apply(Army& army) {
    army.decrease_Morale(20);
}

std::string CommanderDeath::getName() const {
    return "Commander Death";
}