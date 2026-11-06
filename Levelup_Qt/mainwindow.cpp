#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "User.h"

#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("LevelUp");

    ui->welcomeLabel->setTextFormat(Qt::PlainText);
    ui->welcomeLabel->setText(
        QString("Welcome, %1!").arg(QString::fromStdString(getUsername()))
        );

    ui->xpProgressBar->setFormat("%v / %m XP");
    refreshDashboard();

    connect(ui->pushButton, &QPushButton::clicked,
            this, &MainWindow::onAddTask);

    connect(ui->completeTaskButton, &QPushButton::clicked,
            this, &MainWindow::onCompleteTask);

    connect(ui->deleteTaskButton, &QPushButton::clicked,
            this, &MainWindow::onDeleteTask);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshDashboard()
{
    ui->levelLabel->setText(QString("Level %1").arg(level));
    ui->totalXpLabel->setText(QString("Total XP: %1").arg(totalXP));
    ui->xpProgressBar->setRange(0, nextLevelXP);
    ui->xpProgressBar->setValue(currentXP);
}