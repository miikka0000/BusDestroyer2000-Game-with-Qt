#ifndef GAMEOVERDIALOG_H
#define GAMEOVERDIALOG_H

#include "statistisdialog.h"

#include <QDialog>

namespace Ui {
class GameOverDialog;
}

class GameOverDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameOverDialog(QWidget *parent = nullptr);
    ~GameOverDialog();

    void setToolTips();
    void setPlayerPoints();

private slots:
    void on_gameOverCloseButton_clicked();

    void on_playAgainButton_clicked();



    void on_statsButton_clicked();

private:
    Ui::GameOverDialog *ui;
};

#endif // GAMEOVERDIALOG_H
