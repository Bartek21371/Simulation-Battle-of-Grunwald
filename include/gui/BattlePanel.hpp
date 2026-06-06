//
// Created by bart on 31.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_BATTLEPANEL_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_BATTLEPANEL_HPP

#include "core/Battle.hpp"
#include "observer/BattleObserver.hpp"

#include <QWidget>
#include <QLabel>


/**
 * @brief GUI panel displaying battle-wide information.
 */
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
    /**
     * @brief Creates labels used to display current battle state.
     */
    BattlePanel(QWidget* parent = nullptr);

    /**
     * @brief Updates battle information after observer notification.
     */
    void update(const Battle& battle) override;

    /// Displays current battle number.
    void setBattleNumber(int current, int total);
    /// Displays current round count.
    void setRounds(int rounds);
    /// Displays current weather.
    void setWeather(const QString& weather);
    /// Displays Hussars morale.
    void setHussarsMorale(int morale);
    /// Displays Teutonic morale.
    void setTeutonicMorale(int morale);
    /// Displays estimated Hussars victory probability.
    void setHussarsProbability(double probability);
    /// Displays estimated Teutonic victory probability.
    void setTeutonicProbability(double probability);
    /// Displays the latest combat action or random event.
    void setCurrentEvent(const QString& event);
    /// Displays the currently predicted or final winner.
    void setWinner(const QString& winner);
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_BATTLEPANEL_HPP
