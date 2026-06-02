//
// Created by bart on 1.06.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_HUSSARSPANEL_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_HUSSARSPANEL_HPP
#include <QWidget>
#include <QLabel>

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
    HussarsPanel(QWidget* parent = nullptr);

    // Setters
    void setAlive(int alive);

    void setKnights(int knights);
    void setArchers(int archers);
    void setCavalrymans(int cavalrymans);

    void setDamage(double damage);
    void setKills(int kills);
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_HUSSARSPANEL_HPP
