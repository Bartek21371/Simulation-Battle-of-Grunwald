#ifndef SIMULATION_BATTLE_OF_GRUNWALD_BATTLE_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_BATTLE_HPP

#include <string>

#include <core/Army.hpp>
#include <events/Weather.hpp>
#include "BattleStats.hpp"


class Battle {
private:

    Army Hussars;
    Army Teutonic;

    int round{};
    std::string winner{};

    Weather weather;

    BattleStats stats;

    /*;
    std::vector<std::shared_ptr<RandomEvent>> randomEvents;
    */

public:

    Battle(Army& HussarsArmy, Army& TeutonicArmy);

    void start_Battle();

    void do_Round();

    // Getter
    int get_Rounds() const;

    std::string get_Winner() const;

    const Army& get_HussarsArmy() const;
    const Army& get_TeutonicArmy() const;

    std::string get_Weather() const;

    const BattleStats& get_Stats() const;

};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_BATTLE_HPP