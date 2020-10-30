#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include <QSize>

settingsDialog::settingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settingsDialog)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(800,600));
}

settingsDialog::~settingsDialog()
{
    delete ui;
}


void settingsDialog::on_backToMainButton_clicked()
{
    this->close();
}
