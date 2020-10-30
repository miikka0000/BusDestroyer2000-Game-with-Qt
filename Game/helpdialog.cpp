#include "helpdialog.h"
#include "ui_helpdialog.h"

#include <QSize>

helpDialog::helpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::helpDialog)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(800, 700));
    ui->helpTextBrowser->setFixedSize(QSize(800, 700));
    ui->closeHelpButton->move(800 - (2.5 * ui->closeHelpButton->width()), 0);


}

helpDialog::~helpDialog()
{
    delete ui;
}



void helpDialog::on_closeHelpButton_clicked()
{
    this->close();
}
