//
// Created by bart on 31.05.2026.
//

#include <iostream>
#include <string>
#include <fstream>

#include "gui/MainWindow.hpp"

#include "gui/BattlePanel.hpp"
#include "gui/ControlPanel.hpp"
#include "gui/HistoryPanel.hpp"
#include <config/ConfigLoader.hpp>
#include <core/Battle.hpp>
#include <reports/BattleReport.hpp>

#include <QPushButton>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>



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

    battleTimer = new QTimer(this);
    battleTimer->setInterval(200);

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

    connect(
        battleTimer,
        &QTimer::timeout,
        this,
        &MainWindow::battleStep
        );

    connect(
    controlPanel->get_SpeedComboBox(),
    &QComboBox::currentTextChanged,
    this,
    &MainWindow::changeSpeed
);

}

void MainWindow::startBattle()
{
    historyPanel->clearHistoryList();

    if(configPath.isEmpty())
    {
        QMessageBox::warning(
            this,
            "No config",
            "Load configuration first."
            );
        return;
    }

    loadedConfig = ConfigLoader::LoadFromFile(configPath.toStdString(), false);

    Reportfilename = "../assets/reports/battleReport1.csv";

    std::ofstream file(Reportfilename);
    file<<"Battle,Winner,Rounds,Hussars Alive,Teutonic Alive,Hussars Total Damage,Teutonic Total Damage,Hussars Kills,Teutonic Kills,Weather,Status,Date\n";
    file.close();


    currentBattleIndex = 0;

    hussarsWins = 0;
    teutonicWins = 0;

    startNextBattle();
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

void MainWindow::battleStep() {
    currentBattle->do_Round();

    hussarsPanel->setAlive(currentBattle->get_HussarsArmy().count_AliveWarriors());
    teutonicPanel->setAlive(currentBattle->get_TeutonicArmy().count_AliveWarriors());

    hussarsPanel->setDamage(currentBattle->get_Stats().get_HussarsDamage_Dealt());
    teutonicPanel->setDamage(currentBattle->get_Stats().get_TeutonicDamage_Dealt());
    hussarsPanel->setKills(currentBattle->get_Stats().get_HussarsKills());
    teutonicPanel->setKills(currentBattle->get_Stats().get_TeutonicKills());

    // probablity
    int aliveHussars = currentBattle->get_HussarsArmy().count_AliveWarriors();
    int aliveTeutonic = currentBattle->get_TeutonicArmy().count_AliveWarriors();

    int moraleHussars = currentBattle->get_HussarsArmy().get_moraleLevel();
    int moraleTeutonic = currentBattle->get_TeutonicArmy().get_moraleLevel();

    int killsHussars = currentBattle->get_Stats().get_HussarsKills();
    int killsTeutonic = currentBattle->get_Stats().get_TeutonicKills();

    double hussarsPower = aliveHussars*2+moraleHussars+killsHussars;
    double teutonicPower = aliveTeutonic*2+moraleTeutonic+killsTeutonic;

    double totalPower = hussarsPower+teutonicPower;

    if (totalPower > 0) {
        double hussarsProbability = (hussarsPower/totalPower)*100.0;
        double teutonicProbability = (teutonicPower/totalPower)*100.0;

        battlePanel->setHussarsProbability(hussarsProbability);
        battlePanel->setTeutonicProbability(teutonicProbability);

        double diff = std::abs(hussarsProbability-teutonicProbability);

        if (diff < 1.0) {
            battlePanel->setWinner("DRAW");
        }
        else if (hussarsProbability > teutonicProbability) {
            battlePanel->setWinner("HUSSARS");
        }
        else{
            battlePanel->setWinner("TEUTONIC");
        }
    }


    if(currentBattle->is_finished())
    {
        battleTimer->stop();

        currentBattle->finishBattle();

        historyPanel->addBattleResult(
            QString("%1 | Rounds: %2 | Weather: %3 | Alive: %4 vs %5")
            .arg(QString::fromStdString(currentBattle->get_Winner()))
            .arg(currentBattle->get_Rounds())
            .arg(QString::fromStdString(currentBattle->get_Weather()))
            .arg(currentBattle->get_HussarsArmy().count_AliveWarriors())
            .arg(currentBattle->get_TeutonicArmy().count_AliveWarriors())
            );

        BattleReport::save(*currentBattle, Reportfilename, (currentBattleIndex/2)+1);

        if(currentBattle->get_Winner() == "Hussars")
        {
            hussarsWins++;
        }
        else
        {
            teutonicWins++;
        }

        currentBattleIndex += 2;

        delete currentBattle;
        currentBattle = nullptr;

        startNextBattle();

    }
}

void MainWindow::startNextBattle()
{
    if(currentBattleIndex >= loadedConfig.size() - 1)
    {
        historyPanel->addBattleResult(
        "=== Campaign Finished ==="
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

        QString champion =
            (hussarsWins > teutonicWins)
            ? "HUSSARS"
            : "TEUTONIC";

        historyPanel->addBattleResult(
            QString("Campaign Winner: %1")
                .arg(champion)
        );

        return;
    }

    try {

        battlePanel->setBattleNumber((currentBattleIndex/2)+1, loadedConfig.size()/2);

        Army Hussars(loadedConfig[currentBattleIndex]);

        Army Teutonic(loadedConfig[currentBattleIndex + 1]);

        currentBattle = new Battle(Hussars, Teutonic);

        currentBattle->attach(battlePanel);

        battleTimer->start();
    }
    catch (const std::exception& e) {
        BattleReport::save_skipped(Reportfilename, (currentBattleIndex/2)+1, e.what());

        historyPanel->addBattleResult(
        QString("Battle %1 skipped: %2")
            .arg(currentBattleIndex)
            .arg(e.what())
        );

        currentBattleIndex += 2;

        startNextBattle();
    }

}

void MainWindow::changeSpeed() {
    QString speed = controlPanel->get_SpeedComboBox()->currentText();

    if(speed == "Slow")
    {
        battleTimer->setInterval(500);
    }
    else if(speed == "Normal")
    {
        battleTimer->setInterval(200);
    }
    else if(speed == "Fast")
    {
        battleTimer->setInterval(50);
    }
}


/*
 *
    std::string filename = "../assets/reports/battleReport1.csv";

    std::ofstream file(filename);
    file<<"Battle,Winner,Rounds,Hussars Alive,Teutonic Alive,Hussars Total Damage,Teutonic Total Damage,Hussars Kills,Teutonic Kills,Weather,Status,Date\n";
    file.close();

    Army Hussars(config[i]);
    Army Teutonic(config[i+1]);

    currentBattle = new Battle(Hussars, Teutonic);

    currentBattle.attach(battlePanel);
    battleTimer->start(50);

                battlePanel->setRounds(currentBattle.get_Rounds());
                battlePanel->setWeather(QString::fromStdString(currentBattle.get_Weather()));
                battlePanel->setHussarsMorale(currentBattle.get_HussarsArmy().get_moraleLevel());
                battlePanel->setTeutonicMorale(currentBattle.get_TeutonicArmy().get_moraleLevel());
                battlePanel->setCurrentEvent(QString::fromStdString(currentBattle.get_CurrentEvent()));
                battlePanel->setWinner(QString::fromStdString(currentBattle.get_Winner()));








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





            BattleReport::save(currentBattle, filename, battleNumber);


            BattleReport::save_skipped(filename, battleNumber, e.what());
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
    */
