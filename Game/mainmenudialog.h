#ifndef MAINMENUDIALOG_H
#define MAINMENUDIALOG_H

#include <QDialog>

namespace Ui {
class MainMenuDialog;
}

class MainMenuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenuDialog(QWidget *parent = nullptr);
    ~MainMenuDialog();

private:
    Ui::MainMenuDialog *ui;
};

#endif // MAINMENUDIALOG_H
