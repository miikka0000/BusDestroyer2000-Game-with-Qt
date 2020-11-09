#ifndef MAINMENUDIALOG_H
#define MAINMENUDIALOG_H

#include "player.h"
#include "settingsdialog.h"
#include "helpdialog.h"

#include <QDialog>
#include <QString>
#include <QSize>
#include <string>
#include <QSettings>
#include <memory>


namespace Ui {
class MainMenuDialog;
}

class MainMenuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenuDialog(QWidget *parent = nullptr);
    ~MainMenuDialog();
    void setToolTips();

    enum playerConfig {
        spaceshipOption, tankOption, ufoOption,
        fireballOption, missileOption, laserOption,
        musicStateOn, musicStateOff, fireballSound,
        missileSound, blasterSound

    };

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

    void on_settingsButton_clicked();

    void on_helpButton_clicked();


private:
    Ui::MainMenuDialog *ui;

    QSize _menuDialogSize;
    QPixmap _fireballPic = QPixmap(":/images/fireball_16x16.png");
    QPixmap _missilePic = QPixmap(":/images/missile_23x10.png");
    QPixmap _laserPic = QPixmap(":/images/laser_32x32.png");
    std::shared_ptr<QSettings> _playerSettings = std::make_shared<QSettings>();

    bool _tank = false;
    bool _spaceShip = false;
    bool _ufo = false;

    bool _fireball = false;
    bool _missile = false;
    bool _laser = false;

    bool _musicsOn = false;

    QString _playerAlias;


};

#endif // MAINMENUDIALOG_H
