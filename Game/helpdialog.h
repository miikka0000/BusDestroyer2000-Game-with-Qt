#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>

/**
  * @brief Defines an interface that reperesents the helpDialogs's User Interface (Ui).
  */
namespace Ui {
class helpDialog;
}

/**
 * @brief
 * All of the classes done by the student team are found in StudentSide namespace.
 */
namespace StudentSide {

/**
  * @brief Defines a QDialog which offers help to a new player who possibly isn't aware of the game rules, settings or controls etc.
  * The Dialog itself is accessible from MainMenu's "Help" -button.
  */
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
}
#endif // HELPDIALOG_H
