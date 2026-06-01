//
// Created by bart on 31.05.2026.
//

#include "gui/BattlePanel.hpp"

#include <QVBoxLayout>
#include <QGroupBox>
#include <QPixmap>
#include <QHBoxLayout>



// Update for each round stats
void BattlePanel::update(const Battle &battle) {
    setRounds(battle.get_Rounds());

    setWeather(QString::fromStdString(battle.get_Weather()));

    setHussarsMorale(battle.get_HussarsArmy().get_moraleLevel());
    setTeutonicMorale(battle.get_TeutonicArmy().get_moraleLevel());

    setCurrentEvent(QString::fromStdString(battle.get_CurrentEvent()));

}

// Gui look of battle panel
BattlePanel::BattlePanel(QWidget* parent) : QWidget(parent), battle(nullptr) {

    QVBoxLayout* layout = new QVBoxLayout;
    QGroupBox* battleGroup = new QGroupBox("Battle Information", this);
    QVBoxLayout* battleLayout = new QVBoxLayout;

    battleNumberLabel = new QLabel(this);
    battleNumberLabel->setText("Battle Number: -/-");
    battleLayout->addWidget(battleNumberLabel);

    roundLabel = new QLabel(this);
    roundLabel->setText("Rounds: -");
    battleLayout->addWidget(roundLabel);

    weatherLabel = new QLabel(this);
    weatherLabel->setText("Weather: -");
    battleLayout->addWidget(weatherLabel);

    HussarsMoraleLabel = new QLabel(this);
    HussarsMoraleLabel->setText("Hussars Morale: -");
    battleLayout->addWidget(HussarsMoraleLabel);

    TeutonicMoraleLabel = new QLabel(this);
    TeutonicMoraleLabel->setText("Teutonic Morale: -");
    battleLayout->addWidget(TeutonicMoraleLabel);

    VictoryChanceLabel = new QLabel(this);
    VictoryChanceLabel->setText("Victory Chance: -");
    battleLayout->addWidget(VictoryChanceLabel);

    HussarsProbabilityLabel = new QLabel(this);
    HussarsProbabilityLabel->setText("Hussars: -%");
    battleLayout->addWidget(HussarsProbabilityLabel);

    TeutonicProbabilityLabel = new QLabel(this);
    TeutonicProbabilityLabel->setText("Teutonic: -%");
    battleLayout->addWidget(TeutonicProbabilityLabel);

    currentEventLabel = new QLabel(this);
    currentEventLabel->setText("Current Event: -");
    battleLayout->addWidget(currentEventLabel);


    QFont winnerFont;
    winnerFont.setBold(true);
    winnerFont.setPointSize(11);

    winnerLabel = new QLabel(this);
    winnerLabel->setText("Winner: -");
    winnerLabel->setFont(winnerFont);
    battleLayout->addWidget(winnerLabel);

    battleLayout->addStretch();
    battleGroup->setLayout(battleLayout);
    layout->addWidget(battleGroup);
    setLayout(layout);
}


// Setters

void BattlePanel::setBattleNumber(int current, int total) {
    battleNumberLabel->setText(
        QString("Battle %1 / %2")
        .arg(current)
        .arg(total)
    );
}

void BattlePanel::setRounds(int rounds) {
    roundLabel->setText("Rounds: " + QString::number(rounds));
}
void BattlePanel::setWeather(const QString& weather) {
    weatherLabel->setText("Weather: " + weather);
}

void BattlePanel::setHussarsMorale(int morale) {
    HussarsMoraleLabel->setText("Hussars Morale: " + QString::number(morale));
    if (morale >= 70)
        HussarsMoraleLabel->setStyleSheet("color: green;");
    else if (morale <= 30)
        HussarsMoraleLabel->setStyleSheet("color: red;");
    else
        HussarsMoraleLabel->setStyleSheet("color: orange;");
}

void BattlePanel::setTeutonicMorale(int morale) {
    TeutonicMoraleLabel->setText("Teutonic Morale: " + QString::number(morale));
    if (morale >= 70)
        TeutonicMoraleLabel->setStyleSheet("color: green;");
    else if (morale <= 30)
        TeutonicMoraleLabel->setStyleSheet("color: red;");
    else
        TeutonicMoraleLabel->setStyleSheet("color: orange;");
}

void BattlePanel::setCurrentEvent(const QString &event) {
    currentEventLabel->setText("Current event: " + event);
}

void BattlePanel::setWinner(const QString& winner) {
    winnerLabel->setText("Winner: " + winner);

    if (winner == "HUSSARS") {
        winnerLabel->setStyleSheet("color: green");
    }
    else {
        winnerLabel->setStyleSheet("color: red");
    }
}
