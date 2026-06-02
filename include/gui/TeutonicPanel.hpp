//
// Created by bart on 1.06.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_TEUTONICPANEL_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_TEUTONICPANEL_HPP


#include <QWidget>
#include <QLabel>

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
    TeutonicPanel(QWidget* parent = nullptr);

    // Setters
    void setAlive(int alive);

    void setKnights(int knights);
    void setArchers(int archers);
    void setCavalrymans(int cavalrymans);

    void setDamage(double damage);
    void setKills(int kills);
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_TEUTONICPANEL_HPP
