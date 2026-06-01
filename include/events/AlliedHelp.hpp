//
// Created by bart on 1.06.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_ALLIEDHELP_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_ALLIEDHELP_HPP
#include "RandomEvent.hpp"

class AlliedHelp : public RandomEvent {
public:
    void apply(Army& army) override;
    std::string getName() const override;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_ALLIEDHELP_HPP
