#ifndef SIMULATION_BATTLE_OF_GRUNWALD_BATTLE_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_BATTLE_HPP


#include <core/Army.hpp>

class Battle {
private:

    Army Hussars;
    Army Teutonic;
    //if army1.valid && army2.valid
    int round;


    /*Weather weather;
    BattleStats stats;

    std::vector<std::shared_ptr<RandomEvent>> randomEvents;
    */

public:

    Battle(Army& HussarsArmy,Army& TeutonicArmy);

    void start_Battle();

    void do_Round();

    static int random_Number(int min, int max);

    // Getter
    int get_Round() const;


    /*void apply_Weather();
    void activate_Random_Event();*/

    /*BattleResult check_Winner();
    BattleStats& get_Stats();*/

    //int get_Round() const;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_BATTLE_HPP