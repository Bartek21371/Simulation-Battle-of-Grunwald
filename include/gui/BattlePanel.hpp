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

    QLabel* battleNumberLabel;
    QLabel* roundLabel;
    QLabel* weatherLabel;

    QLabel* HussarsMoraleLabel;
    QLabel* TeutonicMoraleLabel;

    QLabel* VictoryChanceLabel;
    QLabel* HussarsProbabilityLabel;
    QLabel* TeutonicProbabilityLabel;

    QLabel* currentEventLabel;

    QLabel* winnerLabel;
public:
    BattlePanel(QWidget* parent = nullptr);

    void update(const Battle& battle) override;

    // Setters
    void setBattleNumber(int current, int total);
    void setRounds(int rounds);
    void setWeather(const QString& weather);
    void setHussarsMorale(int morale);
    void setTeutonicMorale(int morale);
    void setHussarsProbability(int probability);
    void setTeutonicProbability(int probability);
    void setCurrentEvent(const QString& event);
    void setWinner(const QString& winner);
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_BATTLEPANEL_HPP
