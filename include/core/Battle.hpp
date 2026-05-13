#ifndef SIMULATION_BATTLE_OF_GRUNWALD_BATTLE_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_BATTLE_HPP

#include <vector>

class Battle {
private:

    Army Hussars;
    Army TeutonicKnights;

    int round;

    Weather weather;
    BattleStats stats;

    std::vector<std::shared_ptr<RandomEvent>> randomEvents;


public:

    Battle();

    void apply_Weather();

    void activate_Random_Event();

    void do_Round();

    BattleResult check_Winner();

    void start_Battle();

    BattleStats& get_Stats();

    int get_Round() const;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_BATTLE_HPP