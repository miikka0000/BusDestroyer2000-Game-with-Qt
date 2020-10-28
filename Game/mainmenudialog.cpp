#include "mainmenudialog.h"
#include "ui_mainmenudialog.h"

MainMenuDialog::MainMenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenuDialog)
{
    ui->setupUi(this);
    connect(ui->startButton, &QPushButton::clicked,
            this, &QDialog::accept);
    connect(ui->exitButton, &QPushButton::clicked,
            this, &QDialog::reject);
    connect(ui->exitButton, &QPushButton::clicked,
                this, &MainMenuDialog::close);

}

MainMenuDialog::~MainMenuDialog()
{
    delete ui;
}
