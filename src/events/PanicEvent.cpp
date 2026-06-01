//
// Created by bart on 1.06.2026.
//

#include <events/PanicEvent.hpp>

void PanicEvent::apply(Army& army) {
    army.decrease_Morale(10);
}

std::string PanicEvent::getName() const {
    return "Army Panic";
}