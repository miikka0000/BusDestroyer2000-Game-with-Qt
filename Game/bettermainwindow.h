#ifndef BETTERMAINWINDOW_H
#define BETTERMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class BetterMainWindow;
}

class BetterMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BetterMainWindow(QWidget *parent = nullptr);
    ~BetterMainWindow();

private:
    Ui::BetterMainWindow *ui;
};

#endif // BETTERMAINWINDOW_H
