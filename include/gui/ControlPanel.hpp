//
// Created by bart on 31.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_CONTROLPANEL_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_CONTROLPANEL_HPP

#include <QWidget>
#include <QPushButton>
#include <QComboBox>

/**
 * @brief GUI panel with simulation control buttons and speed selector.
 */
class ControlPanel : public QWidget {
private:
    QPushButton* startButton;
    QPushButton* loadConfigButton;
    QPushButton* exitButton;

    QComboBox* speedComboBox;

public:
    /**
     * @brief Creates buttons for loading, starting, exiting and selecting speed.
     */
    ControlPanel(QWidget *parent);

    /// Returns the Start button.
    QPushButton* get_StartButton() const;
    /// Returns the Load button.
    QPushButton* get_LoadButton() const;
    /// Returns the Exit button.
    QPushButton* get_ExitButton() const;

    /// Returns the speed selection combo box.
    QComboBox* get_SpeedComboBox() const;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_CONTROLPANEL_HPP
