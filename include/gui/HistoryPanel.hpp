//
// Created by bart on 31.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_HISTORYPANEL_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_HISTORYPANEL_HPP

#include <QGroupBox>
#include <QListWidget>

class HistoryPanel : public QGroupBox {
private:
    QListWidget* historyList;

public:
    HistoryPanel(QWidget* parent=nullptr);

    void clearHistoryList();

    // Setter
    void addBattleResult(const QString& result);
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_HISTORYPANEL_HPP
