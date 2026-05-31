//
// Created by bart on 31.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_STATISTICSPANEL_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_STATISTICSPANEL_HPP

#include "core/Battle.hpp"
#include "observer/BattleObserver.hpp"

#include <QWidget>
#include <QLabel>


class StatisticsPanel: public QWidget, public BattleObserver {
private:
    Battle* battle;

    QLabel* hussarsDamageLabel;
    QLabel* teutonicDamageLabel;
    QLabel* hussarsKillsLabel;
    QLabel* teutonicKillsLabel;

public:
    StatisticsPanel(QWidget* parent = nullptr);

    void update() override;

    // Setters
    void setHussarsDamage(double damage);
    void setTeutonicDamage(double damage);
    void setHussarsKills(int kills);
    void setTeutonicKills(int kills);
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_STATISTICSPANEL_HPP
