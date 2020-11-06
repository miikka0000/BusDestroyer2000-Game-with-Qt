#ifndef STATISTISDIALOG_H
#define STATISTISDIALOG_H

#include "mainmenudialog.h"

#include <QDialog>
#include <QString>


namespace Ui {
class statistisDialog;
}

class statistisDialog : public QDialog
{
    Q_OBJECT

public:
    explicit statistisDialog(QWidget *parent = nullptr);
    ~statistisDialog();

    void setToolTips();
    void generateStatsString();


private slots:
    void on_exitGameButton_clicked();

    void on_playAgainButton_clicked();

private:
    Ui::statistisDialog *ui;
};

#endif // STATISTISDIALOG_H
