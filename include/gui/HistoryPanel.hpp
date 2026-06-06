//
// Created by bart on 31.05.2026.
//

#ifndef SIMULATION_BATTLE_OF_GRUNWALD_HISTORYPANEL_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_HISTORYPANEL_HPP

#include <QGroupBox>
#include <QListWidget>

/**
 * @brief GUI panel listing completed and skipped battles.
 */
class HistoryPanel : public QGroupBox {
private:
    QListWidget* historyList;

public:
    /**
     * @brief Creates the history list widget.
     */
    HistoryPanel(QWidget* parent=nullptr);

    /// Removes all entries from the history list.
    void clearHistoryList();

    /// Appends one battle or campaign result line.
    void addBattleResult(const QString& result);
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_HISTORYPANEL_HPP
