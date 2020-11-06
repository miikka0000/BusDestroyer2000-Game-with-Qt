#include "gameoverdialog.h"
#include "ui_gameoverdialog.h"
#include "mainmenudialog.h"
#include "playergamescore.h"
#include "tophighscores.h"

#include <QSize>
#include <QSettings>
#include <memory>
#include <QString>


extern std::shared_ptr<gameStatistics> smartStats;
extern std::map<std::shared_ptr<Interface::IActor>, QGraphicsPixmapItem*> smartActors;
extern QString playerAliasName;

GameOverDialog::GameOverDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOverDialog)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(800, 600));
    setToolTips();
    setPlayerPoints();
    highScores = new topHighScores();

    highScores->writeFile();
    highScores->readFile();
    ui->topscoreWidget->setText(highScores->scores);
}

GameOverDialog::~GameOverDialog()
{
    initGameData();
    delete ui;

}

void GameOverDialog::setToolTips()
{
    ui->playAgainButton->setToolTip("Play Again");
    ui->gameOverCloseButton->setToolTip("Close Game");
    ui->statsButton->setToolTip("Show game statistics");

}

void GameOverDialog::setPlayerPoints()
{
    QString points = QString::number(smartStats->givePoints());
    ui->pointsLabel->setText("<p>GAME OVER! You got " + points +
                             " points in total, well done " +
                             playerAliasName + "!");


}

void GameOverDialog::initGameData()
{
    smartStats->initAllValues();
    smartActors.clear();
}

void GameOverDialog::on_gameOverCloseButton_clicked()
{
    this->close();
}

void GameOverDialog::on_playAgainButton_clicked()
{
    initGameData();
    MainMenuDialog *newMainMenu = new MainMenuDialog();
    newMainMenu->show();
    this->close();
}



void GameOverDialog::on_statsButton_clicked()
{
    statistisDialog *statsDialog = new statistisDialog;
    statsDialog->show();
    this->close();
}
