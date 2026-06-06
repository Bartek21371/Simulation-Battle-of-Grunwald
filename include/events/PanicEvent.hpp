//
// Created by bart on 1.06.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_PANICEVENT_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_PANICEVENT_HPP
#include "RandomEvent.hpp"

/**
 * @brief Random event that decreases army morale.
 */
class PanicEvent : public RandomEvent {
public:
    /// Decreases morale of the affected army.
    void apply(Army& army) override;
    /// Returns the display name of the event.
    std::string getName() const override;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_PANICEVENT_HPP
