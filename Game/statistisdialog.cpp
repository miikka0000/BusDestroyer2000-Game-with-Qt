#include "statistisdialog.h"
#include "ui_statistisdialog.h"

extern std::shared_ptr<StudentSide::gameStatistics> smartStats;
namespace StudentSide {

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
    ui->backButton->setToolTip("Back to game over dialog");
}

void statistisDialog::generateStatsString()
{
    QString stats = "<br><b>NONSCALED Score points: </b>" + QString::number(smartStats->givePoints())
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

void StudentSide::statistisDialog::on_backButton_clicked()
{
    this->close();
}
}
