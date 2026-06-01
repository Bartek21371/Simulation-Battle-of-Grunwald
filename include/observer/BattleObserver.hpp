//
// Created by bart on 31.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_BATTLEOBSERVER_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_BATTLEOBSERVER_HPP

// Interface for stats panel and battle panel

class Battle;

class BattleObserver {
public:
    virtual ~BattleObserver() = default;
    virtual void update(const Battle& battle) = 0;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_BATTLEOBSERVER_HPP
