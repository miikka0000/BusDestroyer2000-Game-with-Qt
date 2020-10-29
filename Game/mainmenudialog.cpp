#include "mainmenudialog.h"
#include "ui_mainmenudialog.h"
#include "bettermainwindow.h"
#include <QDebug>

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

void MainMenuDialog::setPlayerName(QString playerNickName)
{

    chosenPlayer->playerName = playerNickName;
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

void MainMenuDialog::on_lineEdit_editingFinished()
{
    setPlayerName(ui->lineEdit->text());
}

void MainMenuDialog::on_spaceshipButton_clicked(bool checked)
{
    if (checked) {
        chosenPlayer->spaceshipChosen = true;
    }
}

void MainMenuDialog::on_tankButton_clicked(bool checked)
{
    if (checked) {
        chosenPlayer->tankChosen = true;
    }
}

void MainMenuDialog::on_ufoButton_clicked(bool checked)
{
    if (checked) {
        chosenPlayer->ufoChosen = true;
    }
}
