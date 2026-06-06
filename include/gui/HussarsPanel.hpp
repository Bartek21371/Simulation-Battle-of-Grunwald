//
// Created by bart on 1.06.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_HUSSARSPANEL_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_HUSSARSPANEL_HPP
#include <QWidget>
#include <QLabel>

/**
 * @brief GUI panel displaying current Hussars army statistics.
 */
class HussarsPanel : public QWidget {
private:

    QLabel* hussarsLabel;
    QLabel* hussarsIMG;

    QLabel* aliveHussarsLabel;
    QLabel* aliveKnightsLabel;
    QLabel* aliveArchersLabel;
    QLabel* aliveCavalrymansLabel;

    QLabel* hussarsDamageLabel;
    QLabel* hussarsKillsLabel;


public:
    /**
     * @brief Creates labels and image for the Hussars army panel.
     */
    HussarsPanel(QWidget* parent = nullptr);

    /// Displays count of all living Hussars warriors.
    void setAlive(int alive);

    /// Displays count of living knights.
    void setKnights(int knights);
    /// Displays count of living archers.
    void setArchers(int archers);
    /// Displays count of living cavalrymen.
    void setCavalrymans(int cavalrymans);

    /// Displays total damage dealt by Hussars.
    void setDamage(double damage);
    /// Displays total kills made by Hussars.
    void setKills(int kills);
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_HUSSARSPANEL_HPP
