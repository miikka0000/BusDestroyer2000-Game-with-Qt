#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include <QSize>
#include <QSettings>

namespace StudentSide {

settingsDialog::settingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settingsDialog)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(800,600));
    this->setWindowTitle("Settings");
    setActionToolTips();
    ui->musicsOnCheckBox->setChecked(false);
    ui->timeComboBox->setCurrentIndex(1);
}

settingsDialog::~settingsDialog()
{
    delete ui;
    _playerSettings->clear();
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
    this->close();
}

void settingsDialog::onMusicsOnClicked()
{
    if(ui->musicsOnCheckBox->isChecked()){
        _musicsOn = true;
        _playerSettings->setValue("music setting", musicStateOn);
    }else if(!ui->musicsOnCheckBox->isChecked()){
        _musicsOn = false;
        _playerSettings->setValue("music setting", musicStateOff);
    }
}

void settingsDialog::setCorrectMusicState()
{
    if(ui->musicsOnCheckBox->isChecked()){
        _playerSettings->setValue("music setting", musicStateOn);
    }else{
        _playerSettings->setValue("music setting", musicStateOff);
    }
}

void settingsDialog::setWantedGameTime()
{
    if (ui->timeComboBox->currentIndex() == 0) {
        _playerSettings->setValue("time setting", gameTime1);
    }
    else if (ui->timeComboBox->currentIndex() == 1) {
        _playerSettings->setValue("time setting", gameTime2);
    }
    else if (ui->timeComboBox->currentIndex() == 2) {
        _playerSettings->setValue("time setting", gameTime3);
    }
}

void settingsDialog::on_saveSettingsButton_clicked()
{
    setCorrectMusicState();
    setWantedGameTime();
}
}
