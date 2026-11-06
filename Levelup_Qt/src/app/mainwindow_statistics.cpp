#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Statistics.h"

#include <QString>

void MainWindow::refreshStatistics()
{
    const TaskStatistics stats = getTaskStatistics();

    ui->totalTasksLabel->setText(
        QString("Total Tasks: %1").arg(stats.total)
        );
    ui->completeTasksLabel->setText(
        QString("Completed Tasks: %1").arg(stats.completed)
        );
    ui->pendingTasksLabel->setText(
        QString("Pending Tasks: %1").arg(stats.pending)
        );
    ui->completionRateLabel->setText(
        QString("Completion rate: %1%").arg(stats.completionRate, 0, 'f', 1)
        );
}