#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>


/**
  * @brief Defines an interface that reperesents the helpDialogs's User Interface (Ui).
  */
namespace Ui {
class helpDialog;
}

class helpDialog : public QDialog
{
    Q_OBJECT

public:
    /**
      * @brief Basic constructor of the class. As a default, parent is set to a nullpointer to QWidget.
      * @post basicProjectile is at initialization state.
      */
    explicit helpDialog(QWidget *parent = nullptr);

    /**
      * @brief GameOverDialog has a basic destructor.
      */
    ~helpDialog();
    void setActionTips();

private slots:
    void on_closeHelpButton_clicked();

private:
    Ui::helpDialog *ui;
};

#endif // HELPDIALOG_H
