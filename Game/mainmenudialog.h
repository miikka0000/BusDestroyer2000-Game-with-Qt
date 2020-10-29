#ifndef MAINMENUDIALOG_H
#define MAINMENUDIALOG_H

#include "player.h"
#include <QDialog>
#include <QString>


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

    enum playerType {
        tankOption, spaceshipOption, ufoOption
    };
    QString playerAlias;


signals:
    void setPlayerName(QString name);
    void setPlayerType(int type);


private slots:
    void on_startButton_clicked();

    void on_exitButton_clicked();

    void on_playerNameEdit_editingFinished();

    void on_spaceshipButton_clicked();

    void on_tankButton_clicked();

    void on_ufoButton_clicked();

private:
    Ui::MainMenuDialog *ui;



    bool tank_ = false;
    bool spaceShip_ = false;
    bool ufo_ = false;


};

#endif // MAINMENUDIALOG_H
