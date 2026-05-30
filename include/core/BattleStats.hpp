//
// Created by bart on 30.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_BATTLESTATS_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_BATTLESTATS_HPP

class BattleStats {
private:
    double HussarsDamage_Dealt{};
    double TeutonicDamage_Dealt{};

    int HussarsKills{};
    int TeutonicKills{};

    /* TODODODODO
    ?????? total hussars and teutonnic
    int numKnights_Hussars{};
    int numArchers_Hussars{};
    int numCavalrymans_Hussars{};

    int numKnights_Teutonic{};
    int numArchers_Teutonic{};
    int numCavalrymans_Teutonic{};

    int moraleLevelHussars{};
    int moraleLevelTeutonic{};

    int ProbabilityVictoryHussars{};
    int ProbabilityVictoryTeutonic{};

    */


public:
    void add_HussarsDamage(double damage);
    void add_TeutonicDamage(double damage);

    void add_HussarsKill();
    void add_TeutonicKill();

    // Getters
    double get_HussarsDamage_Dealt() const;
    double get_TeutonicDamage_Dealt() const;

    int get_HussarsKills() const;
    int get_TeutonicKills() const;

};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_BATTLESTATS_HPP
