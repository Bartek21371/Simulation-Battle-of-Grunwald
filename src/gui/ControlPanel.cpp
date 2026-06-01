//
// Created by bart on 31.05.2026.
//

#include "gui/ControlPanel.hpp"

#include <QBoxLayout>

ControlPanel::ControlPanel(QWidget* parent): QWidget(parent) {

    QVBoxLayout* layout = new QVBoxLayout;

    startButton=new QPushButton("Start", this);
    startButton->setMinimumHeight(50);
    layout->addWidget(startButton);

    loadConfigButton=new QPushButton("Load", this);
    loadConfigButton->setMinimumHeight(50);
    layout->addWidget(loadConfigButton);

    exitButton=new QPushButton("Exit", this);
    exitButton->setMinimumHeight(50);
    layout->addWidget(exitButton);

    speedComboBox=new QComboBox(this);
    speedComboBox->addItem("Slow");
    speedComboBox->addItem("Normal");
    speedComboBox->addItem("Fast");

    speedComboBox->setCurrentText("Normal");

    layout->addWidget(speedComboBox);


    this->setLayout(layout);
}

QPushButton* ControlPanel::get_StartButton() const {
    return startButton;
}

QPushButton* ControlPanel::get_LoadButton() const {
    return loadConfigButton;
}

QPushButton* ControlPanel::get_ExitButton() const {
    return exitButton;
}

QComboBox* ControlPanel::get_SpeedComboBox() const {
    return speedComboBox;
}