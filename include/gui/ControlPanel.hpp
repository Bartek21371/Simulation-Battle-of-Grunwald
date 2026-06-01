//
// Created by bart on 31.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_CONTROLPANEL_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_CONTROLPANEL_HPP

#include <QWidget>
#include <QPushButton>
#include <QComboBox>

class ControlPanel : public QWidget {
private:
    QPushButton* startButton;
    QPushButton* loadConfigButton;
    QPushButton* exitButton;

    QComboBox* speedComboBox;

public:
    ControlPanel(QWidget *parent);

    // Getters
    QPushButton* get_StartButton() const;
    QPushButton* get_LoadButton() const;
    QPushButton* get_ExitButton() const;

    QComboBox* get_SpeedComboBox() const;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_CONTROLPANEL_HPP
