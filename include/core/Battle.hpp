#ifndef SIMULATION_BATTLE_OF_GRUNWALD_BATTLE_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_BATTLE_HPP

#include <string>
#include <vector>

#include <core/Army.hpp>
#include <events/Weather.hpp>
#include "BattleStats.hpp"
#include "observer/BattleObserver.hpp"
#include <events/RandomEvent.hpp>


class Battle {
private:

    Army Hussars;
    Army Teutonic;

    int round{};
    std::string winner{};

    Weather weather;

    BattleStats stats;

    std::vector<BattleObserver*> observers;

    std::string currentEvent;

    std::vector<std::unique_ptr<RandomEvent>> randomEvents;
    int eventsTriggered{};
    const int maxEvents{};
    void triggerRandomEvent();

public:

    Battle(Army& HussarsArmy, Army& TeutonicArmy);

    void start_Battle();

    void do_Round();
    bool is_finished() const;

    void finishBattle();

    void attach(BattleObserver* observer);
    void detach(BattleObserver* observer);
    void notify();

    // Getter
    int get_Rounds() const;

    std::string get_Winner() const;

    const Army& get_HussarsArmy() const;
    const Army& get_TeutonicArmy() const;

    std::string get_Weather() const;

    const BattleStats& get_Stats() const;

    const std::string& get_CurrentEvent() const;

};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_BATTLE_HPP