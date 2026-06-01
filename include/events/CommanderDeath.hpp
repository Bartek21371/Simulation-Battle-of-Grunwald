//
// Created by bart on 1.06.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_COMMANDERDEATH_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_COMMANDERDEATH_HPP
#include "RandomEvent.hpp"

class CommanderDeath : public RandomEvent {
public:
    void apply(Army& army) override;
    std::string getName() const override;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_COMMANDERDEATH_HPP
