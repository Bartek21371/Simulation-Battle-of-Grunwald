//
// Created by bart on 30.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_BATTLESTATS_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_BATTLESTATS_HPP

/**
 * @brief Accumulates damage and kill counters for one battle.
 */
class BattleStats {
private:
    double HussarsDamage_Dealt{};
    double TeutonicDamage_Dealt{};

    int HussarsKills{};
    int TeutonicKills{};

public:
    /// Adds damage dealt by the Hussars army.
    void add_HussarsDamage(double damage);
    /// Adds damage dealt by the Teutonic army.
    void add_TeutonicDamage(double damage);

    /// Increments Hussars kill counter.
    void add_HussarsKill();
    /// Increments Teutonic kill counter.
    void add_TeutonicKill();

    /// Returns total damage dealt by Hussars.
    double get_HussarsDamage_Dealt() const;
    /// Returns total damage dealt by Teutonic army.
    double get_TeutonicDamage_Dealt() const;

    /// Returns number of kills made by Hussars.
    int get_HussarsKills() const;
    /// Returns number of kills made by Teutonic army.
    int get_TeutonicKills() const;

};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_BATTLESTATS_HPP
