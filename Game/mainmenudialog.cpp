#include "mainmenudialog.h"
#include "ui_mainmenudialog.h"
#include "gamewindow.h"
#include "settingsdialog.h"

#include <QString>
#include <QSize>
#include <QSettings>

extern QString playerAliasName;
namespace StudentSide {

MainMenuDialog::MainMenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenuDialog)
{
    ui->setupUi(this);
    _menuDialogSize = QSize(800, 600);
    this->setFixedSize(_menuDialogSize);
    this->setWindowTitle("Main Menu");
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

void MainMenuDialog::setStartGameText(QString text, QString color)
{
    ui->erronousInputLabel->setStyleSheet("QLabel { color :" + color + ";}");
    ui->erronousInputLabel->setFont(QFont("MS Shell Dlg 2", 10));
    ui->erronousInputLabel->setText(text);
}

bool MainMenuDialog::nameIsEmpty(const QString playerName) const
{
    if(playerName.trimmed().isEmpty()){
        return true;
    }
    return false;
}

void MainMenuDialog::on_startButton_clicked()
{
    if((_tank || _spaceShip  || _ufo) && (_fireball || _missile || _laser)
            && !nameIsEmpty(_playerAlias)){

        setStartGameText("A new game is starting, good luck!", "green");
        ui->erronousInputLabel->repaint();

        gameWindow *mainWin = new gameWindow();
        mainWin->show();
        this->close();

    } else if(_playerAlias.isEmpty() && (_tank || _spaceShip || _ufo) &&
              (_fireball || _missile || _laser)){

        setStartGameText("Remember to set player name!");
    }
    else if(!(_tank && _spaceShip && _ufo) && (_fireball || _missile || _laser)
            && !nameIsEmpty(_playerAlias)){

        setStartGameText("Remember to set player type!");

    }else if((_fireball || _missile || _laser) && !(_tank && _spaceShip && _ufo)
             && _playerAlias.isEmpty()){

        setStartGameText("Remember to set player type and"
                         " player name!");

    } else if((_tank || _spaceShip || _ufo) && !(_fireball && _missile && _laser)
              && !nameIsEmpty(_playerAlias)){

        setStartGameText("Remember to set projectile type!");

    } else if((_tank || _spaceShip || _ufo) && !(_fireball && _missile && _laser)
              && _playerAlias.isEmpty()){

        setStartGameText("Remember to set projectile type"
                         " and player name!");

    } else if(!(_tank && _spaceShip && _ufo) && !(_fireball && _missile && _laser)
              && !nameIsEmpty(_playerAlias)){

        setStartGameText("Remember to set projectile"
                         " and player type!");

    }else if(!(_tank || _spaceShip  || _ufo) && !(_fireball || _missile || _laser)
             && _playerAlias.isEmpty()){

        setStartGameText("Remember to set projectile type, "
                         "player name and player type!");

    } else if((_tank || _spaceShip  || _ufo) && (_fireball || _missile || _laser)
              && nameIsEmpty(_playerAlias)){

        setStartGameText("Player name cannot contain only "
                         "whitespace!");
    }
}

void MainMenuDialog::on_exitButton_clicked()
{
    this->close();
    // successful completion of the program
    exit(0);
}

void MainMenuDialog::on_playerNameEdit_editingFinished()
{
    _playerAlias = ui->playerNameEdit->text();
    _playerSettings->setValue("player name setting", _playerAlias);
    playerAliasName = _playerAlias;
}

void MainMenuDialog::on_spaceshipButton_clicked()
{
    _spaceShip = true;
    _tank = false;
    _ufo = false;

    _playerSettings->setValue("player type setting", spaceshipOption);
}

void MainMenuDialog::on_tankButton_clicked()
{
    _tank = true;
    _spaceShip = false;
    _ufo = false;

    _playerSettings->setValue("player type setting", tankOption);
}

void MainMenuDialog::on_ufoButton_clicked()
{
    _ufo = true;
    _tank = false;
    _spaceShip = false;

    _playerSettings->setValue("player type setting", ufoOption);
}

void MainMenuDialog::on_fireballButton_clicked()
{
    _fireball = true;
    _missile = false;
    _laser = false;

    _playerSettings->setValue("projectile type setting", fireballOption);
    _playerSettings->setValue("projectile soundeffect setting", fireballSound);
}

void MainMenuDialog::on_missileButton_clicked()
{
    _fireball = false;
    _missile = true;
    _laser = false;

    _playerSettings->setValue("projectile type setting", missileOption);
    _playerSettings->setValue("projectile soundeffect setting", missileSound);
}

void MainMenuDialog::on_laserButton_clicked()
{
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
}



