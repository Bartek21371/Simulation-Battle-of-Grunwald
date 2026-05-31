//
// Created by bart on 31.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_MAINWINDOW_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_MAINWINDOW_HPP

#include <qboxlayout.h>
#include <QMainWindow>

#include "BattlePanel.hpp"
#include "ControlPanel.hpp"
#include "HistoryPanel.hpp"
#include "StatisticsPanel.hpp"


class MainWindow : public QMainWindow {
private:
    Q_OBJECT
    BattlePanel* battlePanel;
    StatisticsPanel* statisticsPanel;
    ControlPanel* controlPanel;
    HistoryPanel* historyPanel;

    void startBattle();

public:
    MainWindow(QWidget* parent = nullptr);

};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_MAINWINDOW_HPP
