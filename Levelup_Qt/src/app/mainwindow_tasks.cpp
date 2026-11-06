#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Task.h"
#include <QMessageBox>
#include <QString>

void MainWindow::onAddTask()
{
    const QString name = ui->taskNameInput->text().trimmed();

    if (name.isEmpty())
    {
        QMessageBox::information(this, "Add Task", "Enter a task name first.");
        return;
    }

    const int difficultyIndex = ui->difficultyBox->currentIndex();

    if (difficultyIndex < 0)
    {
        QMessageBox::information(this, "Add Task", "Select a difficulty first.");
        return;
    }

    const int reward = addTask(name.toStdString(), difficultyIndex);

    if (reward == 0)
    {
        QMessageBox::warning(this, "Add Task", "Could not add the task.");
        return;
    }

    ui->taskListWidget->addItem(
        QString("%1 (%2 XP) - Pending").arg(name).arg(reward)
        );

    ui->taskNameInput->clear();
    ui->taskNameInput->setFocus();
    refreshStatistics();
}

void MainWindow::onCompleteTask()
{
    const int row = ui->taskListWidget->currentRow();

    if (!completeTask(row))
    {
        QMessageBox::information(
            this, "Complete Task", "Select a task that is still pending."
            );
        return;
    }

    auto *item = ui->taskListWidget->item(row);
    QString text = item->text();
    text.chop(QStringLiteral(" - Pending").size());
    item->setText(text + QStringLiteral(" - Completed"));

    refreshDashboard();
    refreshStatistics();
    refreshAchievements();
}

void MainWindow::onDeleteTask()
{
    const int row = ui->taskListWidget->currentRow();

    if (!deleteTask(row))
    {
        QMessageBox::information(this, "Delete Task", "Select a task first.");
        return;
    }

    delete ui->taskListWidget->takeItem(row);
    refreshStatistics();
}