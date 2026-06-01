//
// Created by bart on 1.06.2026.
//

#include "gui/TeutonicPanel.hpp"

#include <QGroupBox>
#include <QHBoxLayout>


TeutonicPanel::TeutonicPanel(QWidget* parent) {
    QVBoxLayout* layout = new QVBoxLayout;
    QGroupBox* teutonicPanel = new QGroupBox("Teutonic Stats");
    QVBoxLayout* groupLayout = new QVBoxLayout;


    QFont armyFont;
    armyFont.setPointSize(14);
    armyFont.setBold(true);

    teutonicLabel = new QLabel("TEUTONIC", this);
    teutonicLabel->setFont(armyFont);
    teutonicLabel->setAlignment(Qt::AlignCenter);
    groupLayout->addWidget(teutonicLabel);

    teutonicIMG = new QLabel(this);
    groupLayout->addWidget(teutonicIMG);
    QPixmap teutonicPixmap("../assets/images/teutonic.png");
    teutonicIMG->setPixmap(teutonicPixmap.scaled(140,140, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    aliveTeutonicLabel = new QLabel("Alive: -");
    groupLayout->addWidget(aliveTeutonicLabel);
    teutonicDamageLabel = new QLabel("Damage: -");
    groupLayout->addWidget(teutonicDamageLabel);
    teutonicKillsLabel = new QLabel("Kills: -");
    groupLayout->addWidget(teutonicKillsLabel);

    teutonicPanel->setLayout(groupLayout);
    layout->addWidget(teutonicPanel);

    setLayout(layout);


}

// Setters

void TeutonicPanel::setAlive(int alive) {
    aliveTeutonicLabel->setText(
        "Alive: " + QString::number(alive)
    );
}

void TeutonicPanel::setDamage(double damage) {
    teutonicDamageLabel->setText(
        "Damage: " + QString::number(damage)
    );
}

void TeutonicPanel::setKills(int kills) {
    teutonicKillsLabel->setText(
        "Kills: " + QString::number(kills)
    );
}