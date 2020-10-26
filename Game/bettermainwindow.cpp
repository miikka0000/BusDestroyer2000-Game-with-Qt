#include "bettermainwindow.h"
#include "ui_bettermainwindow.h"

BetterMainWindow::BetterMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BetterMainWindow)
{
    ui->setupUi(this);
}

BetterMainWindow::~BetterMainWindow()
{
    delete ui;
}
