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
    QPushButton* saveButton;
    QPushButton* exitButton;
    QPushButton* loadConfigButton;
public:
    ControlPanel(QWidget *parent);

    QPushButton* get_StartButton() const;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_CONTROLPANEL_HPP
