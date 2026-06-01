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