#ifndef MAINMENUDIALOG_H
#define MAINMENUDIALOG_H

#include "player.h"
#include <QDialog>
#include <QString>
#include <QSize>


namespace Ui {
class MainMenuDialog;
}

class MainMenuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenuDialog(QWidget *parent = nullptr);
    ~MainMenuDialog();

    void sendChosenPlayer();
    void sendChosenProjectile();
    void sendChosenMusicState();


    enum playerType {
        tankOption, spaceshipOption, ufoOption

    };
    enum projectileType {
        fireballOption, missileOption, laserOption
    };
    enum musicState {
        musicStateOn, musicStateOff
    };

    QString playerAlias;


signals:
    void setPlayerName(QString name);
    void setPlayerType(int type);
    void setProjectileType(int projectileType);
    void setMusicState(int musicChoice);


private slots:
    void on_startButton_clicked();

    void on_exitButton_clicked();

    void on_playerNameEdit_editingFinished();

    void on_spaceshipButton_clicked();

    void on_tankButton_clicked();

    void on_ufoButton_clicked();

    void on_fireballButton_clicked();

    void on_missileButton_clicked();

    void on_laserButton_clicked();

    void on_musicsOn_clicked();

private:
    Ui::MainMenuDialog *ui;

    bool _tank = false;
    bool _spaceShip = false;
    bool _ufo = false;

    bool _fireball = false;
    bool _missile = false;
    bool _laser = false;

    bool _musicsOn = false;

    QSize menuDialogSize;
    QPixmap _fireballPic = QPixmap(":/images/fireball_16x16.png");
    QPixmap _missilePic = QPixmap(":/images/missile_23x10.png");
    QPixmap _laserPic = QPixmap(":/images/laser_32x32.png");


};

#endif // MAINMENUDIALOG_H
