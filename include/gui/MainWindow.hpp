//
// Created by bart on 31.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_MAINWINDOW_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_MAINWINDOW_HPP

#include <qboxlayout.h>
#include <QMainWindow>
#include <QTimer>

#include "BattlePanel.hpp"
#include "ControlPanel.hpp"
#include "HistoryPanel.hpp"
#include "HussarsPanel.hpp"
#include "TeutonicPanel.hpp"


class MainWindow : public QMainWindow {
private:

    Q_OBJECT

    std::vector<FractionConfig> loadedConfig;

    size_t currentBattleIndex{};

    int hussarsWins{};
    int teutonicWins{};

    BattlePanel* battlePanel;
    HussarsPanel* hussarsPanel;
    TeutonicPanel* teutonicPanel;
    ControlPanel* controlPanel;
    HistoryPanel* historyPanel;

    QTimer* battleTimer = nullptr;
    Battle* currentBattle = nullptr;

    QString configPath = "../assets/configs/testfile.csv";

    void startBattle();
    void loadConfig();
    void startNextBattle();

    std::string Reportfilename;

private slots:
    void battleStep();
    void changeSpeed();

public:
    MainWindow(QWidget* parent = nullptr);

};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_MAINWINDOW_HPP
