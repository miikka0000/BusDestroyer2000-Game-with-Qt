#include "mainmenudialog.h"
#include "ui_mainmenudialog.h"
#include "bettermainwindow.h"


MainMenuDialog::MainMenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenuDialog)
{
    ui->setupUi(this);






}

MainMenuDialog::~MainMenuDialog()
{
    delete ui;
}

void MainMenuDialog::on_startButton_clicked()
{
    BetterMainWindow * mainUi = new BetterMainWindow();
    mainUi->show();
    this->close();
}

void MainMenuDialog::on_exitButton_clicked()
{

    this->close();


}
