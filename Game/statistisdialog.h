#ifndef STATISTISDIALOG_H
#define STATISTISDIALOG_H

#include "mainmenudialog.h"

#include <QDialog>
#include <QString>


/**
  * @brief Defines an interface that reperesents the statistisDialog's User Interface (Ui).
  */
namespace Ui {
class statistisDialog;
}

class statistisDialog : public QDialog
{
    Q_OBJECT

public:
    /**
      * @brief Basic constructor of the class. As a default, parent is set to a nullpointer to QGraphicsItem.
      * @post basicProjectile is at initialization state.
      */
    explicit statistisDialog(QWidget *parent = nullptr);

    /**
      * @brief GameOverDialog has a basic destructor.
      */
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
