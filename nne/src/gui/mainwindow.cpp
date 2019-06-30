#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStyle>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Move to styles.
    setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter, size(),
            qApp->desktop()->availableGeometry()));
    ui->statusBar->showMessage("Hello from status bar!");
}

MainWindow::~MainWindow()
{
    delete ui;
}
