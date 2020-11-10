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

class settingsDialog : public QDialog
{
    Q_OBJECT

public:
    /**
      * @brief Basic constructor of the class. As a default, parent is set to a nullpointer to QGraphicsItem.
      * @post basicProjectile is at initialization state.
      */
    explicit settingsDialog(QWidget *parent = nullptr);

    /**
      * @brief GameOverDialog has a basic destructor.
      */
    ~settingsDialog();
    void setActionToolTips();
    void setCorrectMusicState();
    void setWantedGameTime();

    enum musicState {
        musicStateOn, musicStateOff
    };

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

#endif // SETTINGSDIALOG_H
