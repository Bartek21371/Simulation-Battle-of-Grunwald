//
// Created by bart on 31.05.2026.
//

#include "gui/MainWindow.hpp"

#include "gui/BattlePanel.hpp"
#include "gui/ControlPanel.hpp"
#include "gui/HistoryPanel.hpp"

#include <QPushButton>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

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
    QHBoxLayout* bottomLayout = new QHBoxLayout;


    hussarsPanel = new HussarsPanel(centralWidget);
    teutonicPanel = new TeutonicPanel(centralWidget);

    battlePanel = new BattlePanel(centralWidget);
    controlPanel = new ControlPanel(centralWidget);
    historyPanel = new HistoryPanel(centralWidget);


    mainLayout->addWidget(title);

    /*
    topLayout->addWidget(statisticsPanel);
    topLayout->addWidget(battlePanel);
    topLayout->addWidget(controlPanel);
    */

    topLayout->addWidget(hussarsPanel);
    topLayout->addWidget(battlePanel);
    topLayout->addWidget(teutonicPanel);

    bottomLayout->addWidget(historyPanel);
    bottomLayout->addWidget(controlPanel);


    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(bottomLayout);

    mainLayout->setStretch(0, 0); // title
    mainLayout->setStretch(1, 3); // mid
    mainLayout->setStretch(2, 1); // history

    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // Connect buttons
    connect(
        controlPanel->get_StartButton(),
        &QPushButton::clicked,
        this,
        &MainWindow::startBattle
        );

    connect(
        controlPanel->get_LoadButton(),
        &QPushButton::clicked,
        this,
        &MainWindow::loadConfig
        );

    connect(
    controlPanel->get_ExitButton(),
    &QPushButton::clicked,
    this,
    &QWidget::close
);

}

void MainWindow::startBattle() {
    historyPanel->clearHistoryList();
    if (configPath.isEmpty()) {
        QMessageBox::warning(
            this,
            "No config",
            "Load configuration first."
        );
        return;
    }

    std::vector<FractionConfig> config = ConfigLoader::LoadFromFile(configPath.toStdString(),false);

    int battleNumber{1};

    int hussarsWins{};
    int teutonicWins{};

    std::string filename = "../assets/reports/battleReport1.csv";

    std::ofstream file(filename);
    file<<"Battle,Winner,Rounds,Hussars Alive,Teutonic Alive,Hussars Total Damage,Teutonic Total Damage,Hussars Kills,Teutonic Kills,Weather,Status,Date\n";
    file.close();


    for (size_t i = 0; i < config.size()-1; i+=2) {
        try {
            Army Hussars(config[i]);
            Army Teutonic(config[i+1]);

            Battle battle(Hussars, Teutonic);

            battle.start_Battle();

            battlePanel->setRounds(battle.get_Rounds());
            battlePanel->setWeather(QString::fromStdString(battle.get_Weather()));
            battlePanel->setHussarsMorale(battle.get_HussarsArmy().get_moraleLevel());
            battlePanel->setTeutonicMorale(battle.get_TeutonicArmy().get_moraleLevel());
            battlePanel->setCurrentEvent(QString::fromStdString(battle.get_CurrentEvent()));
            battlePanel->setWinner(QString::fromStdString(battle.get_Winner()));

            hussarsPanel->setDamage(battle.get_Stats().get_HussarsDamage_Dealt());
            teutonicPanel->setDamage(battle.get_Stats().get_TeutonicDamage_Dealt());
            hussarsPanel->setKills(battle.get_Stats().get_HussarsKills());
            teutonicPanel->setKills(battle.get_Stats().get_TeutonicKills());

            hussarsPanel->setAlive(battle.get_HussarsArmy().count_AliveWarriors());
            teutonicPanel->setAlive(battle.get_TeutonicArmy().count_AliveWarriors());


            if (battle.get_Winner()=="HUSSARS") {
                hussarsWins++;
            }
            else {
                teutonicWins++;
            }

            historyPanel->addBattleResult(
                "===================="
            );

            historyPanel->addBattleResult(
                QString("Hussars Wins: %1")
                    .arg(hussarsWins)
            );

            historyPanel->addBattleResult(
                QString("Teutonic Wins: %1")
                    .arg(teutonicWins)
            );

            historyPanel->addBattleResult(
                QString("Total Battles: %1")
                    .arg(hussarsWins + teutonicWins)
            );


            historyPanel->addBattleResult(
                QString("%1 | Rounds: %2 | Weather: %3 | Alive: %4 vs %5")
                .arg(QString::fromStdString(battle.get_Winner()))
                .arg(battle.get_Rounds())
                .arg(QString::fromStdString(battle.get_Weather()))
                .arg(battle.get_HussarsArmy().count_AliveWarriors())
                .arg(battle.get_TeutonicArmy().count_AliveWarriors())
                );


            BattleReport::save(battle, filename, battleNumber);
        }
        catch (const std::exception& e) {
            std::cout<<"Battle skipped: "<<e.what()<<"\n";
            BattleReport::save_skipped(filename, battleNumber, e.what());
        }
        battleNumber++;
    }
    QString champion =
    (hussarsWins > teutonicWins)
        ? "HUSSARS"
        : "TEUTONIC";

    historyPanel->addBattleResult(
    "===================="
    );
    historyPanel->addBattleResult(
    QString("Campaign Winner: %1")
        .arg(champion)
);
}

void MainWindow::loadConfig() {
    QString filePath = QFileDialog::getOpenFileName(this,
        "Select config to open",
        "../assets/configs",
        "CSV Files (*.csv)"
        );

    if (!filePath.isEmpty()) {
        configPath = filePath;
        qDebug() << "Loaded config: "<< configPath;
        QMessageBox::information(
            this,
            "Config loaded",
            "Configuration loaded successfully."
        );
    }
}