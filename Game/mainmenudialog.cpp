#include "mainmenudialog.h"
#include "ui_mainmenudialog.h"
#include "bettermainwindow.h"
#include <QDebug>
#include <QString>


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
    if((tank_ || spaceShip_  || ufo_) && playerAlias != NULL){

        sendChosenPlayer();
        BetterMainWindow *mainUi = new BetterMainWindow();

        mainUi->show();
        this->close();
    } else if(playerAlias == NULL && (tank_ || spaceShip_ || ufo_)){

        ui->erronousInputLabel->setText("Remember to set player name!");
    }
    else if(!(tank_ && spaceShip_ && ufo_) && playerAlias != NULL){
        ui->erronousInputLabel->setText("Remember to set player type!");
    }else if(playerAlias == NULL || !(tank_ && spaceShip_ && ufo_)){
        ui->erronousInputLabel->setText("Remember to set player name and type!");
    }
}


void MainMenuDialog::on_exitButton_clicked()
{
    this->close();
}

void MainMenuDialog::on_playerNameEdit_editingFinished()
{

    playerAlias = ui->playerNameEdit->text();
    qDebug() <<playerAlias;
    //emit setPlayerName(playerAlias);
}


void MainMenuDialog::on_spaceshipButton_clicked()
{

    spaceShip_ = true;
    tank_ = false;
    ufo_ = false;


}

void MainMenuDialog::on_tankButton_clicked()
{
    //qDebug() <<"tank chosen";
    tank_ = true;
    spaceShip_ = false;
    ufo_ = false;

}

void MainMenuDialog::on_ufoButton_clicked()
{
    //qDebug() <<"ufo chosen";
    ufo_ = true;
    tank_ = false;
    spaceShip_ = false;

}

void MainMenuDialog::sendChosenPlayer()
{
    if(tank_){
        qDebug() <<"tank chosen, tank-signal emitted";
        emit setPlayerType(tankOption);
    } else if(spaceShip_){
        qDebug() <<"spaceship chosen, spaceship-signal emitted";
        emit setPlayerType(spaceshipOption);
    } else if(ufo_){
        qDebug() <<"ufo chosen, ufo-signal emitted";
        emit setPlayerType(ufoOption);
    }
    qDebug() << "player Name signal emitted";
    emit setPlayerName(playerAlias);
}
