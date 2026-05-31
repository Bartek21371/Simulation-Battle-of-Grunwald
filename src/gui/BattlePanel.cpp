//
// Created by bart on 31.05.2026.
//

#include "gui/BattlePanel.hpp"

#include <QVBoxLayout>
#include <QGroupBox>

void BattlePanel::update() {
    /*
    battle->get_Rounds();

    battle->get_Weather();

    battle->get_Winner();

    battle->get_HussarsArmy();
    battle->get_TeutonicArmy();
    */

}

BattlePanel::BattlePanel(QWidget* parent) : QWidget(parent), battle(nullptr) {

    QVBoxLayout* layout = new QVBoxLayout;
    QGroupBox* battleGroup = new QGroupBox("Battle Information", this);
    QVBoxLayout* battleLayout = new QVBoxLayout;

    roundsLabel = new QLabel(this);
    roundsLabel->setText("Rounds: 20");
    battleLayout->addWidget(roundsLabel);

    weatherLabel = new QLabel(this);
    weatherLabel->setText("Weather: Sunny");
    battleLayout->addWidget(weatherLabel);

    winnerLabel = new QLabel(this);
    winnerLabel->setText("Winner: Hussars");
    battleLayout->addWidget(winnerLabel);

    battleLayout->addStretch();
    battleGroup->setLayout(battleLayout);
    layout->addWidget(battleGroup);
    setLayout(layout);
}

// Setters

void BattlePanel::setRounds(int rounds) {
    roundsLabel->setText("Rounds: " + QString::number(rounds));
}
void BattlePanel::setWeather(const QString& weather) {
    weatherLabel->setText("Weather: " + weather);
}
void BattlePanel::setWinner(const QString& winner) {
    winnerLabel->setText("Winner: " + winner);
}
