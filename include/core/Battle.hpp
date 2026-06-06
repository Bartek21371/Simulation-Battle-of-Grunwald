#ifndef SIMULATION_BATTLE_OF_GRUNWALD_BATTLE_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_BATTLE_HPP

#include <string>
#include <vector>

#include <core/Army.hpp>
#include <events/Weather.hpp>
#include "BattleStats.hpp"
#include "observer/BattleObserver.hpp"
#include <events/RandomEvent.hpp>


/**
 * @brief Controls the simulation of one battle between two armies.
 *
 * Battle owns copied army instances, tracks weather, statistics and random
 * events, and notifies registered observers after state changes.
 */
class Battle {
private:

    Army Hussars;
    Army Teutonic;

    int round{};
    std::string winner;

    Weather weather;

    BattleStats stats;

    std::vector<BattleObserver*> observers;

    std::string currentEvent;

    std::vector<std::unique_ptr<RandomEvent>> randomEvents;
    int eventsTriggered{};
    const int maxEvents{};
    void triggerRandomEvent();

public:

    /**
     * @brief Creates a battle from two prepared armies.
     */
    Battle(Army& HussarsArmy, Army& TeutonicArmy);

    /**
     * @brief Starts the battle loop in non-GUI usage.
     */
    void start_Battle();

    /**
     * @brief Executes one combat round and notifies observers.
     */
    void do_Round();
    /**
     * @brief Checks whether one army has no living warriors.
     */
    bool is_finished() const;

    /**
     * @brief Determines and stores the final winner.
     */
    void finishBattle();

    /**
     * @brief Registers an observer notified after battle updates.
     */
    void attach(BattleObserver* observer);
    /**
     * @brief Unregisters an observer.
     */
    void detach(BattleObserver* observer);
    /**
     * @brief Calls update on all registered observers.
     */
    void notify();

    /// Returns current round number.
    int get_Rounds() const;

    /// Returns winner name after the battle is finished.
    std::string get_Winner() const;

    /// Returns the Hussars army state.
    const Army& get_HussarsArmy() const;
    /// Returns the Teutonic army state.
    const Army& get_TeutonicArmy() const;

    /// Returns weather name as text.
    std::string get_Weather() const;

    /// Returns accumulated battle statistics.
    const BattleStats& get_Stats() const;

    /// Returns text describing the last combat action or random event.
    const std::string& get_CurrentEvent() const;

};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_BATTLE_HPP
