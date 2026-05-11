#ifndef SIMULATION_BATTLE_OF_GRUNWALD_BATTLE_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_BATTLE_HPP

#include <vector>

class Battle {
private:
    Army Hussars;
    Army TeutonicKnight;

    int round = 0;

    Weather weather;
    BattleStats stats;

    std::vector<std::shared_ptr<RandomEvent>> randomEvents;


public:

    Battle(const Army& hussarsArmy,
           const Army& teutonicArmy,
           const Weather& battleWeather);

    void apply_Weather();

    void activate_Random_Event();

    void activate_Random_Event();

    void do_Round();

    BattleResult check_Winner();

    void start_Battle();

    BattleStats& get_Stats();

    int get_Round() const;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_BATTLE_HPP