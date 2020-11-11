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
      * @post helpDialog is at initialization state.
      */
    explicit helpDialog(QWidget *parent = nullptr);

    /**
      * @brief helpDialog has a basic destructor.
      */
    ~helpDialog();

    /**
     * @brief setActionTips sets tool tip in the helpDialog's GUI to guide the player (shown when user hovers mouse on top of the red close button on the top right corner).
     * @pre -
     * @post ToolTip is shown to the user of the software when hovering mouse above GUI's red close button. Exception guarantee: nothrow.
     */
    void setActionTips();

private slots:
    void on_closeHelpButton_clicked();

private:
    Ui::helpDialog *ui;
};

#endif // HELPDIALOG_H
