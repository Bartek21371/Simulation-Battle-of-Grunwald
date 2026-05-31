//
// Created by bart on 31.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_BATTLEPANEL_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_BATTLEPANEL_HPP

#include "core/Battle.hpp"
#include "observer/BattleObserver.hpp"

#include <QWidget>
#include <QLabel>


class BattlePanel : public QWidget, public BattleObserver {
private:
    Battle* battle;

    QLabel* roundsLabel;
    QLabel* weatherLabel;
    QLabel* winnerLabel;

public:
    BattlePanel(QWidget* parent = nullptr);

    void update() override;

    // Setters
    void setRounds(int rounds);
    void setWeather(const QString& weather);
    void setWinner(const QString& winner);
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_BATTLEPANEL_HPP
