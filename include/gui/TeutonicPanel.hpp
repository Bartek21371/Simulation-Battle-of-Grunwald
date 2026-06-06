//
// Created by bart on 1.06.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_TEUTONICPANEL_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_TEUTONICPANEL_HPP


#include <QWidget>
#include <QLabel>

/**
 * @brief GUI panel displaying current Teutonic army statistics.
 */
class TeutonicPanel : public QWidget {
private:

    QLabel* teutonicLabel;
    QLabel* teutonicIMG;

    QLabel* aliveTeutonicLabel;
    QLabel* aliveKnightsLabel;
    QLabel* aliveArchersLabel;
    QLabel* aliveCavalrymansLabel;

    QLabel* teutonicDamageLabel;
    QLabel* teutonicKillsLabel;

public:
    /**
     * @brief Creates labels and image for the Teutonic army panel.
     */
    TeutonicPanel(QWidget* parent = nullptr);

    /// Displays count of all living Teutonic warriors.
    void setAlive(int alive);

    /// Displays count of living knights.
    void setKnights(int knights);
    /// Displays count of living archers.
    void setArchers(int archers);
    /// Displays count of living cavalrymen.
    void setCavalrymans(int cavalrymans);

    /// Displays total damage dealt by Teutonic army.
    void setDamage(double damage);
    /// Displays total kills made by Teutonic army.
    void setKills(int kills);
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_TEUTONICPANEL_HPP
