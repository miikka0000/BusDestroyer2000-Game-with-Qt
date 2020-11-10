#ifndef GAMEOVERDIALOG_H
#define GAMEOVERDIALOG_H

#include "statistisdialog.h"
#include "tophighscores.h"

#include <QDialog>


/**
  * @brief Defines an interface that reperesents the GameOverDialog's User Interface (Ui).
  */
namespace Ui {
class GameOverDialog;
}

class GameOverDialog : public QDialog
{
    Q_OBJECT

public:
    /**
      * @brief Basic constructor for GameOverDialog.
      * @post GameOverDialog is at initialization state.
      */
    explicit GameOverDialog(QWidget *parent = nullptr);

    /**
      * @brief GameOverDialog has a basic destructor.
      */
    ~GameOverDialog();

    /**
     * @brief setToolTips sets tool tips in the GameOverDialog's GUI to guide the player (shown when player hovers mouse on top of a button or a label etc.)
     * @pre -
     * @post ToolTips are shown to the user of the software when hovering mouse above buttons, labels or other items of the GUI. Exception guarantee: nothrow.
     */
    void setToolTips();

    /**
     * @brief setPlayerPoints shows the UNSCALED (not scaled by the chosen game duration) points that the player got in the game.
     * @pre -
     * @post Player is shown the points in the topmost header in GameOverDialog. Exception guarantee: nothrow.
     */
    void setPlayerPoints();

    /**
     * @brief initGameData initializes the player Statistics and Actors drawn in the game map in preparation for a new game session.
     * @pre -
     * @post the player Statistics and Actors drawn in the game map are initialized. Exception guarantee: nothrow.
     */
    void initGameData();

private slots:
    void on_gameOverCloseButton_clicked();

    void on_playAgainButton_clicked();

    void on_statsButton_clicked();

private:
    Ui::GameOverDialog *ui;
    topHighScores *_highScores;
};

#endif // GAMEOVERDIALOG_H
