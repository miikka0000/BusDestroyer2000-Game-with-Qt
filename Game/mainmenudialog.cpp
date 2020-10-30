#include "mainmenudialog.h"
#include "ui_mainmenudialog.h"
#include "gamesetupdata.h"
#include "gamewindow.h"
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
     _playerData = new setUp::gameSetUpData();
}

MainMenuDialog::~MainMenuDialog()
{
    delete ui;
}

void MainMenuDialog::on_startButton_clicked()
{
    if((_tank || _spaceShip  || _ufo) && (_fireball || _missile || _laser)
            && playerAlias != NULL){
        GameWindow *mainWin = new GameWindow();



        //savePlayerChoices();
        //qDebug()<<_playerData->playerName;
        //qDebug()<<_playerData->tankChosen;
        //savePlayerChoices();
        mainWin->show();


        this->close();

    } else if(playerAlias == NULL && (_tank || _spaceShip || _ufo) &&
              (_fireball || _missile || _laser)){

        ui->erronousInputLabel->setText("Remember to set player name!");
    }
    else if(!(_tank && _spaceShip && _ufo) && (_fireball || _missile || _laser)
            && playerAlias != NULL){

        ui->erronousInputLabel->setText("Remember to set player type!");

    }else if(playerAlias == NULL && !(_tank && _spaceShip && _ufo) &&
             !(_fireball && _missile && _laser)){

        ui->erronousInputLabel->setText("Remember to set projectile type, player name and player type!");

    } else if((_tank || _spaceShip || _ufo) && !(_fireball && _missile && _laser)
              && playerAlias != NULL){

        ui->erronousInputLabel->setText("Remember to set projectile type!");

    } else if((_tank || _spaceShip || _ufo) && !(_fireball && _missile && _laser)
              && playerAlias == NULL){
        ui->erronousInputLabel->setText("Remember to set projectile type and player name!");

    } else if(!(_tank && _spaceShip && _ufo) && !(_fireball && _missile && _laser)
              && playerAlias != NULL){
        ui->erronousInputLabel->setText("Remember to set projectile and player type!");

    }else if(!(_tank && _spaceShip && _ufo) && (_fireball || _missile || _laser)
             && playerAlias == NULL){
        ui->erronousInputLabel->setText("Remember to set player type and player name!");
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
    qDebug() <<"spaceship chosen";
    _spaceShip = true;
    _tank = false;
    _ufo = false;

    _playerData->setTrue(_playerData->spaceshipChosen);
    _playerData->setFalse(_playerData->ufoChosen);
    _playerData->setFalse(_playerData->tankChosen);
}

void MainMenuDialog::on_tankButton_clicked()
{
    qDebug() <<"tank chosen";
    _tank = true;
    _spaceShip = false;
    _ufo = false;

    setUp::gameSetUpData().setTrue(setUp::gameSetUpData().tankChosen);
    setUp::gameSetUpData().setFalse(setUp::gameSetUpData().ufoChosen);
    setUp::gameSetUpData().setFalse(setUp::gameSetUpData().spaceshipChosen);
}

void MainMenuDialog::on_ufoButton_clicked()
{
    qDebug() <<"ufo chosen";
    _ufo = true;
    _tank = false;
    _spaceShip = false;

    setUp::gameSetUpData().setTrue(setUp::gameSetUpData().ufoChosen);
    setUp::gameSetUpData().setFalse(setUp::gameSetUpData().tankChosen);
    setUp::gameSetUpData().setFalse(setUp::gameSetUpData().spaceshipChosen);
}

void MainMenuDialog::savePlayerChoices()
{


    if(_tank){
        setUp::gameSetUpData().setTrue(setUp::gameSetUpData().tankChosen);

    }else if(_spaceShip){
        setUp::gameSetUpData().setTrue(setUp::gameSetUpData().spaceshipChosen);

    }else if(_ufo){
        setUp::gameSetUpData().setTrue(setUp::gameSetUpData().ufoChosen);
    }
    if(_fireball){
        setUp::gameSetUpData().setTrue(setUp::gameSetUpData().fireballChosen);

    } else if(_missile){
        setUp::gameSetUpData().setTrue(setUp::gameSetUpData().missileChosen);

    } else if(_laser){
        setUp::gameSetUpData().setTrue(setUp::gameSetUpData().laserChosen);

    }
    if(_musicsOn){
        setUp::gameSetUpData().setTrue(setUp::gameSetUpData().musicsOn);

    } /*if(playerAlias != NULL){
        _playerData->playerName = playerAlias;}*/


}


void MainMenuDialog::on_fireballButton_clicked()
{
    qDebug()<< "fireball clicked";
    _fireball = true;
    _missile = false;
    _laser = false;
}

void MainMenuDialog::on_missileButton_clicked()
{
    qDebug()<< "missile clicked";
    _fireball = false;
    _missile = true;
    _laser = false;
}

void MainMenuDialog::on_laserButton_clicked()
{
    qDebug()<< "laser clicked";
    _fireball = false;
    _missile = false;
    _laser = true;
}

void MainMenuDialog::on_musicsOn_clicked()
{
    if(ui->musicsOn->checkState() == 2){
        qDebug()<<"musics on";
        _musicsOn = true;
    }else{
        _musicsOn = false;
        qDebug()<<"musics off";
    }
}
