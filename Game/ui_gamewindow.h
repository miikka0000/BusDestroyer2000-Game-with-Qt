/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *scoreLabel;
    QLCDNumber *pointsLCD;
    QVBoxLayout *verticalLayout_3;
    QLabel *clockLabel;
    QLCDNumber *clockLCD;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;

    void setupUi(QMainWindow *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QString::fromUtf8("GameWindow"));
        GameWindow->setWindowModality(Qt::NonModal);
        GameWindow->resize(800, 600);
        GameWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(GameWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMouseTracking(false);
        centralwidget->setAutoFillBackground(false);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scoreLabel = new QLabel(centralwidget);
        scoreLabel->setObjectName(QString::fromUtf8("scoreLabel"));
        QFont font;
        font.setPointSize(10);
        scoreLabel->setFont(font);
        scoreLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(scoreLabel);

        pointsLCD = new QLCDNumber(centralwidget);
        pointsLCD->setObjectName(QString::fromUtf8("pointsLCD"));
        pointsLCD->setFont(font);
        pointsLCD->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 222, 255);"));
        pointsLCD->setSmallDecimalPoint(true);

        verticalLayout_2->addWidget(pointsLCD);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        clockLabel = new QLabel(centralwidget);
        clockLabel->setObjectName(QString::fromUtf8("clockLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(clockLabel->sizePolicy().hasHeightForWidth());
        clockLabel->setSizePolicy(sizePolicy1);
        clockLabel->setFont(font);
        clockLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(clockLabel);

        clockLCD = new QLCDNumber(centralwidget);
        clockLCD->setObjectName(QString::fromUtf8("clockLCD"));
        clockLCD->setFont(font);
        clockLCD->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 222, 255);"));
        clockLCD->setSmallDecimalPoint(true);

        verticalLayout_3->addWidget(clockLCD);


        horizontalLayout->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMaximumSize(QSize(16777215, 16777215));
        graphicsView->setAutoFillBackground(true);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        gridLayout->addWidget(graphicsView, 1, 0, 1, 1);

        GameWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GameWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        GameWindow->setMenuBar(menubar);

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameWindow)
    {
        GameWindow->setWindowTitle(QCoreApplication::translate("GameWindow", "BusDestroyer2000", nullptr));
        scoreLabel->setText(QCoreApplication::translate("GameWindow", "Score", nullptr));
        clockLabel->setText(QCoreApplication::translate("GameWindow", "Time Left", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
