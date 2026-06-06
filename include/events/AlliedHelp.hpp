//
// Created by bart on 1.06.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_ALLIEDHELP_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_ALLIEDHELP_HPP
#include "RandomEvent.hpp"

/**
 * @brief Random event that adds reinforcements and increases morale.
 */
class AlliedHelp : public RandomEvent {
public:
    /// Adds warriors and morale to the affected army.
    void apply(Army& army) override;
    /// Returns the display name of the event.
    std::string getName() const override;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_ALLIEDHELP_HPP
