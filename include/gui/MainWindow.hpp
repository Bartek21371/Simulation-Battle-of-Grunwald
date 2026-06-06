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


/**
 * @brief Main Qt window coordinating configuration, simulation and reports.
 */
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

    QString configPath = "../assets/configs/";

    /// Starts a campaign from the selected configuration and creates the report file.
    void startBattle();
    /// Opens a file dialog and stores the selected CSV configuration path.
    void loadConfig();
    /// Starts the next battle pair or displays the final campaign summary.
    void startNextBattle();

    std::string ReportFilename;

private slots:
    /// Executes one timer-driven battle step and refreshes all GUI panels.
    void battleStep();
    /// Updates the battle timer interval from the speed combo box.
    void changeSpeed();

public:
    /**
     * @brief Builds the main application window and connects UI signals.
     */
    MainWindow(QWidget* parent = nullptr);

};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_MAINWINDOW_HPP
