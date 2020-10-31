#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include "player.h"
#include "basicprojectile.h"
#include "mainmenudialog.h"

#include "bonusitem.h"


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QTimer>
#include <QPixmap>
#include <QPalette>
#include <QImage>
#include <QBrush>
#include <QPaintEvent>
#include <vector>
#include <QColor>
#include <QSettings>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

    void resizeEvent(QResizeEvent * event);
    void setPicture(QImage img);
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void setLCDStyle();
    void spawnBonusItem();
    void addPlayerPoints();
    //void keyReleaseEvent(QKeyEvent * keyEvent);
    std::vector<int> getAvailableSize();
    MainMenuDialog *giveDialog() {return _mainMenu;};


    BonusItem *bonusObject;


    int screenWidth = 800;
    int screenHeight = 600;

    int interval = 500;
    QImage bkgndSmall = QImage(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    QImage bkgndBig = QImage(":/offlinedata/offlinedata/kartta_iso_1095x592.png");


private:
    Ui::GameWindow *ui;
    QTimer *mainTimer;
    QTimer *bonusTimer;
    QGraphicsScene * _scene;
    Player * _player;
    QPixmap _pixmapBg = QPixmap(":/offlinedata/offlinedata/kartta_iso_1095x592.png");
    bool _largeMode = false;
    MainMenuDialog *_mainMenu;
    QSettings _playerSettings;


};

#endif // GAMEWINDOW_H
