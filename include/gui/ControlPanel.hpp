//
// Created by bart on 31.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_CONTROLPANEL_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_CONTROLPANEL_HPP

#include <QWidget>
#include <QPushButton>

class ControlPanel : public QWidget {
private:
    QPushButton* startButton;
    QPushButton* loadConfigButton;
    QPushButton* exitButton;
public:
    ControlPanel(QWidget *parent);

    QPushButton* get_StartButton() const;
    QPushButton* get_LoadButton() const;
    QPushButton* get_ExitButton() const;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_CONTROLPANEL_HPP
