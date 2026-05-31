//
// Created by bart on 31.05.2026.
//

#include "gui/MainWindow.hpp"

#include "gui/BattlePanel.hpp"
#include "gui/ControlPanel.hpp"
#include "gui/HistoryPanel.hpp"
#include "gui/StatisticsPanel.hpp"

#include <QPushButton>
#include <QDebug>



#include <iostream>
#include <string>
#include <fstream>
#include <config/ConfigLoader.hpp>
#include <core/Battle.hpp>
#include <reports/BattleReport.hpp>


// Gui

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
    setWindowTitle("Simulation Battle of Grunwald");
    resize(1000, 700);

    // Change design of window
    setStyleSheet(
    "QMainWindow { background-color: #1e1e1e; }"

    "QGroupBox {"
    " color: white;"
    " border: 2px solid #444;"
    " border-radius: 5px;"
    " margin-top: 10px;"
    " font-weight: bold;"
    "}"

    "QGroupBox::title {"
    " subcontrol-origin: margin;"
    " left: 10px;"
    " padding: 0 5px;"
    "}"

    "QLabel {"
    " color: white;"
    "}"

    "QPushButton {"
    " background-color: #303030;"
    " color: white;"
    " padding: 8px;"
    " border: 1px solid #555;"
    "}"
    );

    QWidget* centralWidget = new QWidget(this);

    QLabel* title = new QLabel("Simulation Battle of Grunwald", this);
    title->setAlignment(Qt::AlignCenter);
    QFont font;
    font.setPointSize(20);
    font.setBold(true);
    title->setFont(font);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    QHBoxLayout* topLayout = new QHBoxLayout;


    statisticsPanel = new StatisticsPanel(centralWidget);
    battlePanel = new BattlePanel(centralWidget);
    controlPanel = new ControlPanel(centralWidget);
    historyPanel = new HistoryPanel(centralWidget);


    mainLayout->addWidget(title);

    topLayout->addWidget(statisticsPanel);
    topLayout->addWidget(battlePanel);
    topLayout->addWidget(controlPanel);

    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(historyPanel);

    mainLayout->setStretch(0, 0); // title
    mainLayout->setStretch(1, 3); // mid
    mainLayout->setStretch(2, 1); // history

    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // Connect button
    connect(
        controlPanel->get_StartButton(),
        &QPushButton::clicked,
        this,
        &MainWindow::startBattle
        );


}

void MainWindow::startBattle() {

    std::vector<FractionConfig> config = ConfigLoader::LoadFromFile("../assets/configs/testfile_someinfected.csv",false);

    Army Hussars(config[0]);
    Army Teutonic(config[1]);

    Battle battle(Hussars, Teutonic);

    battle.start_Battle();

    battlePanel->setRounds(battle.get_Rounds());
    battlePanel->setWeather(QString::fromStdString(battle.get_Weather()));
    battlePanel->setWinner(QString::fromStdString(battle.get_Winner()));

    statisticsPanel->setHussarsDamage(battle.get_Stats().get_HussarsDamage_Dealt());
    statisticsPanel->setTeutonicDamage(battle.get_Stats().get_TeutonicDamage_Dealt());
    statisticsPanel->setHussarsKills(battle.get_Stats().get_HussarsKills());
    statisticsPanel->setTeutonicKills(battle.get_Stats().get_TeutonicKills());

    historyPanel->addBattleResult(
        QString("Winner %1 | Rounds %2")
        .arg(QString::fromStdString(battle.get_Winner()))
        .arg(battle.get_Rounds())
        );

}