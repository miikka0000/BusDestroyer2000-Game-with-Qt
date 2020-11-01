#include "gameoverdialog.h"
#include "ui_gameoverdialog.h"
#include "mainmenudialog.h"
#include "playergamescore.h"

#include <QSize>
#include <QSettings>
#include <memory>
#include <QString>

extern std::shared_ptr<playerGameScore> smartPlayerScore;

GameOverDialog::GameOverDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOverDialog)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(800, 600));
    setToolTips();
    setPlayerPoints();
}

GameOverDialog::~GameOverDialog()
{
    delete ui;
}

void GameOverDialog::setToolTips()
{
    ui->playAgainButton->setToolTip("Play Again");
    ui->gameOverCloseButton->setToolTip("Close Game");
}

void GameOverDialog::setPlayerPoints()
{
    QString points = QString::number(smartPlayerScore->getPlayerScore());
    ui->pointsLabel->setText("<p>GAME OVER! You got " + points +
                             " points in total, well done!");

}

void GameOverDialog::on_gameOverCloseButton_clicked()
{
    this->close();
}

void GameOverDialog::on_playAgainButton_clicked()
{
    MainMenuDialog *newMainMenu = new MainMenuDialog();
    newMainMenu->exec();
    this->close();
}
