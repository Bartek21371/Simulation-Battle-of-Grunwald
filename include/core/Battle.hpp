#ifndef SIMULATION_BATTLE_OF_GRUNWALD_BATTLE_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_BATTLE_HPP

#include <vector>

#include <core/Army.hpp>

class Battle {
private:

    Army Hussars;
    Army TeutonicKnights;
    //if army1.valid && army2.valid
    int round;

    Weather weather;
    BattleStats stats;

    std::vector<std::shared_ptr<RandomEvent>> randomEvents;


public:

    Battle();

    void apply_Weather();
    void activate_Random_Event();
    static int random_Number(int min, int max);

    void start_Battle();
    void do_Round();
    BattleResult check_Winner();
    BattleStats& get_Stats();

    int get_Round() const;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_BATTLE_HPP