#include "gameoverdialog.h"
#include "ui_gameoverdialog.h"
#include "mainmenudialog.h"

#include <QSize>
#include <QSettings>

GameOverDialog::GameOverDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOverDialog)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(800, 600));
    setToolTips();
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
