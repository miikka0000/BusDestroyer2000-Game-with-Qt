#ifndef MAINMENUDIALOG_H
#define MAINMENUDIALOG_H

#include "player.h"
#include <QDialog>


namespace Ui {
class MainMenuDialog;
}

class MainMenuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenuDialog(QWidget *parent = nullptr);
    ~MainMenuDialog();

    void setPlayerName(QString playerNickName);



private slots:
    void on_startButton_clicked();

    void on_exitButton_clicked();

    void on_lineEdit_editingFinished();

    void on_spaceshipButton_clicked(bool checked);

    void on_tankButton_clicked(bool checked);

    void on_ufoButton_clicked(bool checked);

private:
    Ui::MainMenuDialog *ui;
    Player* chosenPlayer = new Player();


};

#endif // MAINMENUDIALOG_H
