#include "mainmenudialog.h"
#include "ui_mainmenudialog.h"
#include "gamewindow.h"
#include "settingsdialog.h"
#include "gameoverdialog.h"


#include <QDebug>
#include <QString>
#include <QSize>
#include <QSettings>

MainMenuDialog::MainMenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenuDialog)
{
    ui->setupUi(this);
    _menuDialogSize = QSize(800, 600);
    this->setFixedSize(_menuDialogSize);
    setToolTips();

    _playerSettings->setValue("music setting", settingsDialog::musicStateOff);
    _playerSettings->setValue("time setting", settingsDialog::gameTime2);

}

MainMenuDialog::~MainMenuDialog()
{
    delete ui;
}

void MainMenuDialog::setToolTips()
{
    ui->exitButton->setToolTip("Exit Game");
    ui->startButton->setToolTip("Start Game");
    ui->settingsButton->setToolTip("Go to Settings");
    ui->helpButton->setToolTip("About the Game");
    ui->playerNameEdit->setToolTip("Set player name here");

    ui->spaceshipButton->setToolTip("Choose Spaceship");
    ui->tankButton->setToolTip("Choose Tank");
    ui->ufoButton->setToolTip("Choose UFO");

    ui->fireballButton->setToolTip("Choose Fireball");
    ui->missileButton->setToolTip("Choose Missile");
    ui->laserButton->setToolTip("Choose Laser");

}

void MainMenuDialog::on_startButton_clicked()
{
    if((_tank || _spaceShip  || _ufo) && (_fireball || _missile || _laser)
            && _playerAlias != NULL){


        GameWindow *mainWin = new GameWindow();
        mainWin->show();

        this->close();

    } else if(_playerAlias == NULL && (_tank || _spaceShip || _ufo) &&
              (_fireball || _missile || _laser)){

        ui->erronousInputLabel->setText("Remember to set player name!");
    }
    else if(!(_tank && _spaceShip && _ufo) && (_fireball || _missile || _laser)
            && _playerAlias != NULL){

        ui->erronousInputLabel->setText("Remember to set player type!");

    }else if((_fireball || _missile || _laser) && !(_tank && _spaceShip && _ufo)
             && _playerAlias == NULL){
        ui->erronousInputLabel->setText("Remember to set player type and"
                                        " player name!");

    } else if((_tank || _spaceShip || _ufo) && !(_fireball && _missile && _laser)
              && _playerAlias != NULL){

        ui->erronousInputLabel->setText("Remember to set projectile type!");

    } else if((_tank || _spaceShip || _ufo) && !(_fireball && _missile && _laser)
              && _playerAlias == NULL){
        ui->erronousInputLabel->setText("Remember to set projectile type"
                                        " and player name!");

    } else if(!(_tank && _spaceShip && _ufo) && !(_fireball && _missile && _laser)
              && _playerAlias != NULL){
        ui->erronousInputLabel->setText("Remember to set projectile"
                                        " and player type!");

    }else {
        ui->erronousInputLabel->setText("Remember to set projectile type, "
                                        "player name and player type!");
    }
}

void MainMenuDialog::on_exitButton_clicked()
{
    this->close();
}

void MainMenuDialog::on_playerNameEdit_editingFinished()
{
    _playerAlias = ui->playerNameEdit->text();
    _playerSettings->setValue("player name setting", _playerAlias);
}

void MainMenuDialog::on_spaceshipButton_clicked()
{
    //qDebug() <<"spaceship chosen";
    _spaceShip = true;
    _tank = false;
    _ufo = false;

    _playerSettings->setValue("player type setting", spaceshipOption);
}

void MainMenuDialog::on_tankButton_clicked()
{
    //qDebug() <<"tank chosen";
    _tank = true;
    _spaceShip = false;
    _ufo = false;

    _playerSettings->setValue("player type setting", tankOption);
}

void MainMenuDialog::on_ufoButton_clicked()
{
    //qDebug() <<"ufo chosen";
    _ufo = true;
    _tank = false;
    _spaceShip = false;

    _playerSettings->setValue("player type setting", ufoOption);
}

void MainMenuDialog::on_fireballButton_clicked()
{
    //qDebug()<< "fireball clicked";
    _fireball = true;
    _missile = false;
    _laser = false;

    _playerSettings->setValue("projectile type setting", fireballOption);
    _playerSettings->setValue("projectile soundeffect setting", fireballSound);
}

void MainMenuDialog::on_missileButton_clicked()
{
    //qDebug()<< "missile clicked";
    _fireball = false;
    _missile = true;
    _laser = false;

    _playerSettings->setValue("projectile type setting", missileOption);
    _playerSettings->setValue("projectile soundeffect setting", missileSound);
}

void MainMenuDialog::on_laserButton_clicked()
{
    //qDebug()<< "laser clicked";
    _fireball = false;
    _missile = false;
    _laser = true;


    _playerSettings->setValue("projectile type setting", laserOption);
    _playerSettings->setValue("projectile soundeffect setting", blasterSound);
}

void MainMenuDialog::on_settingsButton_clicked()
{
    settingsDialog *mainSettingsDialog = new settingsDialog(this);
    mainSettingsDialog->exec();
}

void MainMenuDialog::on_helpButton_clicked()
{
    helpDialog *gameHelpDialog = new helpDialog(this);
    gameHelpDialog->exec();
}



void MainMenuDialog::on_pushButton_clicked()
{
    GameOverDialog *t = new GameOverDialog();
    t->exec();
}
