#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class settingsDialog;
}

class settingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit settingsDialog(QWidget *parent = nullptr);
    ~settingsDialog();
    void setActionToolTips();
    void setCorrectMusicState();

    enum musicState {
        musicStateOn, musicStateOff
    };

private slots:


    void on_backToMainButton_clicked();

    void on_musicsOn_clicked();

    void on_saveSettingsButton_clicked();

private:
    Ui::settingsDialog *ui;
    bool _musicsOn;
};

#endif // SETTINGSDIALOG_H
