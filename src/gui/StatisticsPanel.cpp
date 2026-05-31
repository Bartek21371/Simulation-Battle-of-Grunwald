//
// Created by bart on 31.05.2026.
//

#include "gui/StatisticsPanel.hpp"

#include <QVBoxLayout>
#include <QGroupBox>

void StatisticsPanel::update() {
    //battle->get_Stats();
}

StatisticsPanel::StatisticsPanel(QWidget* parent) : QWidget(parent), battle(nullptr) {

    QVBoxLayout* layout = new QVBoxLayout;
    QGroupBox* statsGroup = new QGroupBox("Battle Statistics", this);
    QVBoxLayout* statsLayout = new QVBoxLayout;


    hussarsDamageLabel = new QLabel(this);
    hussarsDamageLabel->setText("Hussars Total Damage: 0");
    statsLayout->addWidget(hussarsDamageLabel);

    teutonicDamageLabel = new QLabel(this);
    teutonicDamageLabel->setText("Teutonic Total Damage: 0");
    statsLayout->addWidget(teutonicDamageLabel);

    hussarsKillsLabel = new QLabel(this);
    hussarsKillsLabel->setText("Hussars Total Kills: 0");
    statsLayout->addWidget(hussarsKillsLabel);

    teutonicKillsLabel = new QLabel(this);
    teutonicKillsLabel->setText("Teutonic Total Kills: 0");
    statsLayout->addWidget(teutonicKillsLabel);

    statsLayout->addStretch();
    statsGroup->setLayout(statsLayout);
    layout->addWidget(statsGroup);
    setLayout(layout);
}

// Setters
void StatisticsPanel::setHussarsDamage(double damage) {
    hussarsDamageLabel->setText("Hussars Total Damage: " + QString::number(damage));
}
void StatisticsPanel::setTeutonicDamage(double damage) {
    teutonicDamageLabel->setText("Teutonic Total Damage: " + QString::number(damage));
}
void StatisticsPanel::setHussarsKills(int kills) {
    hussarsKillsLabel->setText("Hussars Total Kills: " + QString::number(kills));
}
void StatisticsPanel::setTeutonicKills(int kills) {
    teutonicKillsLabel->setText("Teutonic Total Kills: " + QString::number(kills));
}



