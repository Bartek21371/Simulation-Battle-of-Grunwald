//
// Created by bart on 1.06.2026.
//

#include "gui/HussarsPanel.hpp"

#include <complex>
#include <QGroupBox>
#include <QHBoxLayout>


HussarsPanel::HussarsPanel(QWidget* parent) {
    QVBoxLayout* layout = new QVBoxLayout;
    QGroupBox* hussarsPanel = new QGroupBox("Hussars Stats");
    QVBoxLayout* groupLayout = new QVBoxLayout;


    QFont armyFont;
    armyFont.setPointSize(14);
    armyFont.setBold(true);

    hussarsLabel = new QLabel("HUSSARS", this);
    hussarsLabel->setFont(armyFont);
    hussarsLabel->setAlignment(Qt::AlignCenter);
    groupLayout->addWidget(hussarsLabel);


    hussarsIMG = new QLabel(this);
    groupLayout->addWidget(hussarsIMG);
    QPixmap hussarsPixmap("../assets/images/hussars.png");
    hussarsIMG->setPixmap(hussarsPixmap.scaled(140,140, Qt::KeepAspectRatio, Qt::SmoothTransformation));


    aliveHussarsLabel = new QLabel("Alive: -");
    groupLayout->addWidget(aliveHussarsLabel);
    hussarsDamageLabel = new QLabel("Damage: -");
    groupLayout->addWidget(hussarsDamageLabel);
    hussarsKillsLabel = new QLabel("Kills: -");
    groupLayout->addWidget(hussarsKillsLabel);

    hussarsPanel->setLayout(groupLayout);
    layout->addWidget(hussarsPanel);

    setLayout(layout);


}

// Setters

void HussarsPanel::setAlive(int alive) {
    aliveHussarsLabel->setText(
        "Alive: " + QString::number(alive)
    );
}

void HussarsPanel::setDamage(double damage) {
    hussarsDamageLabel->setText(
        "Damage: " + QString::number(damage)
    );
}

void HussarsPanel::setKills(int kills) {
    hussarsKillsLabel->setText(
        "Kills: " + QString::number(kills)
    );
}