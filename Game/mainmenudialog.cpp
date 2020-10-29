#include "mainmenudialog.h"
#include "ui_mainmenudialog.h"
#include "bettermainwindow.h"
#include <QDebug>
#include <QString>
#include <QSize>


MainMenuDialog::MainMenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenuDialog)
{
    ui->setupUi(this);
    menuDialogSize = QSize(800, 600);
    this->setFixedSize(menuDialogSize);
}

MainMenuDialog::~MainMenuDialog()
{
    delete ui;
}

void MainMenuDialog::on_startButton_clicked()
{
    if((_tank || _spaceShip  || _ufo) && playerAlias != NULL){

        sendChosenPlayer();
        this->close();
    } else if(playerAlias == NULL && (_tank || _spaceShip || _ufo)){

        ui->erronousInputLabel->setText("Remember to set player name!");
    }
    else if(!(_tank && _spaceShip && _ufo) && playerAlias != NULL){
        ui->erronousInputLabel->setText("Remember to set player type!");
    }else if(playerAlias == NULL || !(_tank && _spaceShip && _ufo)){
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
}

void MainMenuDialog::on_spaceshipButton_clicked()
{
    _spaceShip = true;
    _tank = false;
    _ufo = false;
}

void MainMenuDialog::on_tankButton_clicked()
{
    _tank = true;
    _spaceShip = false;
    _ufo = false;
}

void MainMenuDialog::on_ufoButton_clicked()
{    
    _ufo = true;
    _tank = false;
    _spaceShip = false;
}

void MainMenuDialog::sendChosenPlayer()
{
    if(_tank){
        qDebug() <<"tank chosen, tank-signal emitted";
        emit setPlayerType(tankOption);
    } else if(_spaceShip){
        qDebug() <<"spaceship chosen, spaceship-signal emitted";
        emit setPlayerType(spaceshipOption);
    } else if(_ufo){
        qDebug() <<"ufo chosen, ufo-signal emitted";
        emit setPlayerType(ufoOption);
    }
    qDebug() << "player Name signal emitted";
    emit setPlayerName(playerAlias);
}



void MainMenuDialog::on_fireballButton_clicked()
{
    _fireball = true;
    _missile = false;
    _laser = false;
}

void MainMenuDialog::on_missileButton_clicked()
{
    _fireball = false;
    _missile = true;
    _laser = false;
}

void MainMenuDialog::on_laserButton_clicked()
{
    _fireball = false;
    _missile = false;
    _laser = true;
}
