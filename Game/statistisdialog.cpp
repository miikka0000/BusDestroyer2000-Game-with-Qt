#include "statistisdialog.h"
#include "ui_statistisdialog.h"

extern std::shared_ptr<gameStatistics> smartStats;

statistisDialog::statistisDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistisDialog)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(800, 600));
    this->setWindowTitle("Statistics");
    generateStatsString();
    setToolTips();
}

statistisDialog::~statistisDialog()
{
    delete ui;
}

void statistisDialog::setToolTips()
{
    ui->exitGameButton->setToolTip("Exit game");
    ui->playAgainButton->setToolTip("Start a new game");
}

void statistisDialog::generateStatsString()
{
    QString stats = "<br><b>Score points: </b>" + QString::number(smartStats->givePoints())
            + "<br><br>" +
            "<b>Collected diamonds: </b>" + QString::number(smartStats->giveCollectedDiamonds())
            + "<br><br>" +
            "<b>Destroyed Nysses: </b>" + QString::number(smartStats->giveDestroyedNysses())
            + "<br><br>" +
            "<b>Eliminated passengers: </b>" +
            QString::number(smartStats->giveDestroyedPassengers()) + "<br><br>";

    ui->statsTextBrowser->append(stats);
    ui->statsTextBrowser->setAlignment(Qt::AlignLeft);
}

void statistisDialog::on_exitGameButton_clicked()
{
    this->close();
}

void statistisDialog::on_playAgainButton_clicked()
{
    MainMenuDialog *newMainMenu = new MainMenuDialog();
    newMainMenu->show();
    this->close();
}
