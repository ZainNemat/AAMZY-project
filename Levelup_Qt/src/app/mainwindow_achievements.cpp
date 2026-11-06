#include "mainwindow.h"
#include "Achievement.h"
#include "ui_mainwindow.h"

#include <QString>

void MainWindow::refreshAchievements()
{
    ui->achievementListWidget->clear();

    for (const Achievement& achievement : getAchievements())
    {
        const QString status = achievement.unlocked
                                   ? QStringLiteral("Unlocked")
                                   : QStringLiteral("Locked");

        ui->achievementListWidget->addItem(
            QStringLiteral("%1 — %2 [%3]")
                .arg(QString::fromUtf8(achievement.name),
                     QString::fromUtf8(achievement.description),
                     status)
            );
    }
}