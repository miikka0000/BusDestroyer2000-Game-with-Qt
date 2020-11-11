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
#include <QFont>


/**
  * @brief Defines an interface that reperesents the MainMenuDialog's User Interface (Ui).
  */
namespace Ui {
class MainMenuDialog;
}

class MainMenuDialog : public QDialog
{
    Q_OBJECT

public:
    /**
      * @brief Basic constructor of the class. As a default, parent is set to a nullpointer to QWidget.
      * @post MainMenuDialog is at initialization state.
      */
    explicit MainMenuDialog(QWidget *parent = nullptr);

    /**
      * @brief MainMenuDialog has a basic destructor.
      */
    ~MainMenuDialog();

    /**
     * @brief setToolTips sets tool tips in the MainMenuDialog's GUI to guide the player (shown when player hovers mouse on top of a button or a label etc.)
     * @pre -
     * @post ToolTips are shown to the user of the software when hovering mouse above buttons, labels or other items of the GUI. Exception guarantee: nothrow.
     */
    void setToolTips();

    /**
     * @brief setStartGameText sets a string to QLabel in desired color.
     * @param String to-be-shown in the QLabel and the color of the string.
     * @pre The QLabel where the text is shown, exists.
     * @post Desired string is set to the QLabel. Exception guarantee: nothrow.
     */
    void setStartGameText(QString text, QString color = "red");

    /**
     * @brief nameIsEmpty checks and validates a QString which is set in the MainMenuDialog
     * @param String in QString format.
     * @pre -
     * @return Returns true if the string given as a parameter contains ONLY whitespace characters, otherwise returns false.
     * @post Boolean has been returned to tell if the string contains only whitespace or not. Exception guarantee: strong.
     */
    bool nameIsEmpty(const QString playerName) const;

    // enum to store all the different player choices/settings.
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
    const QPixmap _fireballPic = QPixmap(":/images/fireball_16x16.png");
    const QPixmap _missilePic = QPixmap(":/images/missile_23x10.png");
    const QPixmap _laserPic = QPixmap(":/images/laser_32x32.png");
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
