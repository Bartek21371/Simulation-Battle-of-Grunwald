//
// Created by bart on 31.05.2026.
//

#include "gui/HistoryPanel.hpp"

#include <QBoxLayout>
#include <QWidget>

HistoryPanel::HistoryPanel(QWidget *parent) {

    QVBoxLayout* layout = new QVBoxLayout();
    QVBoxLayout* historyLayout = new QVBoxLayout;

    QGroupBox* historyGroup = new QGroupBox("Battle History", this);

    historyList = new QListWidget(this);

    historyLayout->addWidget(historyList);
    historyGroup->setLayout(historyLayout);
    layout->addWidget(historyGroup);
    setLayout(layout);

}

void HistoryPanel::addBattleResult(const QString& result) {
    historyList->addItem(result);
}