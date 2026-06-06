//
// Created by bart on 31.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_BATTLEOBSERVER_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_BATTLEOBSERVER_HPP

class Battle;

/**
 * @brief Observer interface used by GUI panels that react to battle updates.
 */
class BattleObserver {
public:
    /// Allows deleting observers through a base pointer.
    virtual ~BattleObserver() = default;
    /**
     * @brief Receives the current battle state.
     * @param battle Battle that changed.
     */
    virtual void update(const Battle& battle) = 0;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_BATTLEOBSERVER_HPP
