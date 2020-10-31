#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include <QSize>
#include <QSettings>
#include <QDebug>

settingsDialog::settingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settingsDialog)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(800,600));
    setActionToolTips();
}

settingsDialog::~settingsDialog()
{
    delete ui;
}

void settingsDialog::setActionToolTips()
{
    ui->backToMainButton->setToolTip("Back to Main Menu");
    ui->saveSettingsButton->setToolTip("Save Settings");
    ui->musicsOnCheckBox->setToolTip("<p> Check to enable<br>sound effects<br></p>");
    ui->timeComboBox->setToolTip("Set game duration");
}


void settingsDialog::on_backToMainButton_clicked()
{
    setCorrectMusicState();
    this->close();
}

void settingsDialog::on_musicsOn_clicked()
{
    QSettings playerSettings;
    if(ui->musicsOnCheckBox->isChecked()){
        qDebug()<<"musics on";
        _musicsOn = true;
        playerSettings.setValue("music setting", musicStateOn);
    }else if(!ui->musicsOnCheckBox->isChecked()){
        _musicsOn = false;
        qDebug()<<"musics off";
        playerSettings.setValue("music setting", musicStateOff);
    }
}

void settingsDialog::setCorrectMusicState()
{
    QSettings setting;

    if(ui->musicsOnCheckBox->isChecked() || _musicsOn){
        setting.setValue("music setting", musicStateOn);
    }else{
        setting.setValue("music setting", musicStateOff);
    }
}

void settingsDialog::on_saveSettingsButton_clicked()
{
    setCorrectMusicState();
}
