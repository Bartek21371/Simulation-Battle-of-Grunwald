//
// Created by bart on 1.06.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_COMMANDERDEATH_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_COMMANDERDEATH_HPP
#include "RandomEvent.hpp"

/**
 * @brief Random event that simulates commander death by lowering morale.
 */
class CommanderDeath : public RandomEvent {
public:
    /// Decreases morale of the affected army.
    void apply(Army& army) override;
    /// Returns the display name of the event.
    std::string getName() const override;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_COMMANDERDEATH_HPP
