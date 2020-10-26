#include "mainmenudialog.h"
#include "ui_mainmenudialog.h"

MainMenuDialog::MainMenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenuDialog)
{
    ui->setupUi(this);
}

MainMenuDialog::~MainMenuDialog()
{
    delete ui;
}
