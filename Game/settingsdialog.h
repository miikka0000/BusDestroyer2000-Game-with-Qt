#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QSettings>
#include <memory>

/**
  * @brief Defines an interface that reperesents the settingsDialog's User Interface (Ui).
  */
namespace Ui {
class settingsDialog;
}

/**
 * @brief
 * All of the classes done by the student team are found in StudentSide namespace.
 */
namespace StudentSide {

/**
  * @brief Defines a QDialog which offers a separate settings window where the player can set music on/off and alter the game duration.
  * The Dialog itself is accessible from MainMenu's "Settings" -button.
  * If the player does not make any changes to the settings (which isn't compulsory), the default settings are used: musics off and game duration 2 minutes.
  * Beware that if you don't press the "Save" -button in the settingsDialog, your changes to the settings won't come into effect and the program will use the default settings!
  */
class settingsDialog : public QDialog
{
    Q_OBJECT

public:
    /**
      * @brief Basic constructor of the class. As a default, parent is set to a nullpointer to QGraphicsItem.
      * @post settingsDialog is at initialization state.
      */
    explicit settingsDialog(QWidget *parent = nullptr);

    /**
      * @brief settingsDialog has a basic destructor.
      */
    ~settingsDialog();

    /**
     * @brief setActionToolTips sets tool tips in the settingsDialog's GUI to guide the player (shown when player hovers mouse on top of a button or a label etc.)
     * @pre -
     * @post ToolTips are shown to the user of the software when hovering mouse above buttons, labels or other items of the GUI. Exception guarantee: nothrow.
     */
    void setActionToolTips();

    /**
     * @brief setCorrectMusicState saves the music setting chosen by the player.
     * @pre -
     * @post Chosen music setting has been saved. Exception guarantee: nothrow.
     */
    void setCorrectMusicState();

    /**
     * @brief setWantedGameTime saves the game duration chosen by the player.
     * @pre -
     * @post Chosen game time duration setting has been saved. Exception guarantee: nothrow.
     */
    void setWantedGameTime();

    // enum to store the music state options
    enum musicState {
        musicStateOn, musicStateOff
    };

    // enum to store all the 3 different game duration options (1-3 min)
    enum gameTime {
        gameTime1, gameTime2, gameTime3
    };

private slots:

    void on_backToMainButton_clicked();

    void onMusicsOnClicked();

    void on_saveSettingsButton_clicked();

private:
    Ui::settingsDialog *ui;
    bool _musicsOn = false;
    std::shared_ptr<QSettings> _playerSettings = std::make_shared<QSettings>();
};
}
#endif // SETTINGSDIALOG_H
