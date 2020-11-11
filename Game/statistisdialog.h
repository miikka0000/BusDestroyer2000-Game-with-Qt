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

/**
 * @brief
 * All of the classes done by the student team are found in StudentSide namespace.
 */
namespace StudentSide {

/**
  * @brief Defines a QDialog which offers statisctics of the game played by the player.
  * The Dialog itself is accessible from GameOverDialog's "Statistics" -button.
  */
class statistisDialog : public QDialog
{
    Q_OBJECT

public:
    /**
      * @brief Basic constructor of the class. As a default, parent is set to a nullpointer to QGraphicsItem.
      * @post statistisDialog is at initialization state.
      */
    explicit statistisDialog(QWidget *parent = nullptr);

    /**
      * @brief statistisDialog has a basic destructor.
      */
    ~statistisDialog();

    /**
     * @brief setToolTips sets tool tips in the statistisDialog's GUI to guide the player (shown when player hovers mouse on top of a button or a label etc.)
     * @pre -
     * @post ToolTips are shown to the user of the software when hovering mouse above buttons, labels or other items of the GUI. Exception guarantee: nothrow.
     */
    void setToolTips();

    /**
     * @brief generateStatsString creates and adds player's statistical data of a single game into the QTextBrowser in statisticsDialog.
     * @pre -
     * @post Player game statisctics are shown to the user of the software in the statisticsDialog. Exception guarantee: nothrow.
     */
    void generateStatsString();


private slots:
    void on_exitGameButton_clicked();

    void on_playAgainButton_clicked();

private:
    Ui::statistisDialog *ui;
};
}
#endif // STATISTISDIALOG_H
