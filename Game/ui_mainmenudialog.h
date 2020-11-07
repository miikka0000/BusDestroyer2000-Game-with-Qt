/********************************************************************************
** Form generated from reading UI file 'mainmenudialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENUDIALOG_H
#define UI_MAINMENUDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenuDialog
{
public:
    QLabel *erronousInputLabel;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *projectileTypeLabel;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *fireballButton;
    QRadioButton *missileButton;
    QRadioButton *laserButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *fireballLabel;
    QLabel *missileLabel;
    QLabel *laserLabel;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *playerTypeLabel;
    QHBoxLayout *horizontalLayout;
    QRadioButton *spaceshipButton;
    QRadioButton *tankButton;
    QRadioButton *ufoButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *spaceShipLabel;
    QLabel *tankLabel;
    QLabel *ufoLabel;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_2;
    QLabel *playerNameLabel;
    QLineEdit *playerNameEdit;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *startButton;
    QPushButton *exitButton;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *settingsButton;
    QPushButton *helpButton;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_3;
    QLabel *mainHeaderLabel;
    QLabel *subHeaderLabel;
    QPushButton *pushButton;
    QButtonGroup *playerButtonGroup;
    QButtonGroup *proctileButtonGroup;

    void setupUi(QDialog *MainMenuDialog)
    {
        if (MainMenuDialog->objectName().isEmpty())
            MainMenuDialog->setObjectName(QString::fromUtf8("MainMenuDialog"));
        MainMenuDialog->setEnabled(true);
        MainMenuDialog->resize(659, 479);
        MainMenuDialog->setMinimumSize(QSize(659, 479));
        MainMenuDialog->setMaximumSize(QSize(659, 479));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        MainMenuDialog->setFont(font);
        MainMenuDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 222, 255);"));
        erronousInputLabel = new QLabel(MainMenuDialog);
        erronousInputLabel->setObjectName(QString::fromUtf8("erronousInputLabel"));
        erronousInputLabel->setGeometry(QRect(10, 410, 641, 21));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(erronousInputLabel->sizePolicy().hasHeightForWidth());
        erronousInputLabel->setSizePolicy(sizePolicy);
        erronousInputLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 133, 26);\n"
"font: 10pt \"MS Shell Dlg 2\";"));
        layoutWidget1 = new QWidget(MainMenuDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 270, 641, 131));
        verticalLayout_6 = new QVBoxLayout(layoutWidget1);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        projectileTypeLabel = new QLabel(layoutWidget1);
        projectileTypeLabel->setObjectName(QString::fromUtf8("projectileTypeLabel"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        projectileTypeLabel->setFont(font1);

        verticalLayout_5->addWidget(projectileTypeLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        fireballButton = new QRadioButton(layoutWidget1);
        proctileButtonGroup = new QButtonGroup(MainMenuDialog);
        proctileButtonGroup->setObjectName(QString::fromUtf8("proctileButtonGroup"));
        proctileButtonGroup->addButton(fireballButton);
        fireballButton->setObjectName(QString::fromUtf8("fireballButton"));
        sizePolicy.setHeightForWidth(fireballButton->sizePolicy().hasHeightForWidth());
        fireballButton->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        fireballButton->setFont(font2);

        horizontalLayout_3->addWidget(fireballButton);

        missileButton = new QRadioButton(layoutWidget1);
        proctileButtonGroup->addButton(missileButton);
        missileButton->setObjectName(QString::fromUtf8("missileButton"));
        sizePolicy.setHeightForWidth(missileButton->sizePolicy().hasHeightForWidth());
        missileButton->setSizePolicy(sizePolicy);
        missileButton->setFont(font2);

        horizontalLayout_3->addWidget(missileButton);

        laserButton = new QRadioButton(layoutWidget1);
        proctileButtonGroup->addButton(laserButton);
        laserButton->setObjectName(QString::fromUtf8("laserButton"));
        sizePolicy.setHeightForWidth(laserButton->sizePolicy().hasHeightForWidth());
        laserButton->setSizePolicy(sizePolicy);
        laserButton->setFont(font2);

        horizontalLayout_3->addWidget(laserButton);


        verticalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout_6->addLayout(verticalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        fireballLabel = new QLabel(layoutWidget1);
        fireballLabel->setObjectName(QString::fromUtf8("fireballLabel"));
        sizePolicy.setHeightForWidth(fireballLabel->sizePolicy().hasHeightForWidth());
        fireballLabel->setSizePolicy(sizePolicy);
        fireballLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/fireball_16x16.png")));

        horizontalLayout_4->addWidget(fireballLabel);

        missileLabel = new QLabel(layoutWidget1);
        missileLabel->setObjectName(QString::fromUtf8("missileLabel"));
        sizePolicy.setHeightForWidth(missileLabel->sizePolicy().hasHeightForWidth());
        missileLabel->setSizePolicy(sizePolicy);
        missileLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/missile_23x10.png")));

        horizontalLayout_4->addWidget(missileLabel);

        laserLabel = new QLabel(layoutWidget1);
        laserLabel->setObjectName(QString::fromUtf8("laserLabel"));
        sizePolicy.setHeightForWidth(laserLabel->sizePolicy().hasHeightForWidth());
        laserLabel->setSizePolicy(sizePolicy);
        laserLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/laser_32x32.png")));

        horizontalLayout_4->addWidget(laserLabel);


        verticalLayout_6->addLayout(horizontalLayout_4);

        layoutWidget2 = new QWidget(MainMenuDialog);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 140, 641, 131));
        verticalLayout_4 = new QVBoxLayout(layoutWidget2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        playerTypeLabel = new QLabel(layoutWidget2);
        playerTypeLabel->setObjectName(QString::fromUtf8("playerTypeLabel"));
        sizePolicy.setHeightForWidth(playerTypeLabel->sizePolicy().hasHeightForWidth());
        playerTypeLabel->setSizePolicy(sizePolicy);
        playerTypeLabel->setFont(font1);
        playerTypeLabel->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(playerTypeLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        spaceshipButton = new QRadioButton(layoutWidget2);
        playerButtonGroup = new QButtonGroup(MainMenuDialog);
        playerButtonGroup->setObjectName(QString::fromUtf8("playerButtonGroup"));
        playerButtonGroup->addButton(spaceshipButton);
        spaceshipButton->setObjectName(QString::fromUtf8("spaceshipButton"));
        sizePolicy.setHeightForWidth(spaceshipButton->sizePolicy().hasHeightForWidth());
        spaceshipButton->setSizePolicy(sizePolicy);
        spaceshipButton->setFont(font2);
        spaceshipButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(spaceshipButton);

        tankButton = new QRadioButton(layoutWidget2);
        playerButtonGroup->addButton(tankButton);
        tankButton->setObjectName(QString::fromUtf8("tankButton"));
        sizePolicy.setHeightForWidth(tankButton->sizePolicy().hasHeightForWidth());
        tankButton->setSizePolicy(sizePolicy);
        tankButton->setFont(font2);
        tankButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(tankButton);

        ufoButton = new QRadioButton(layoutWidget2);
        playerButtonGroup->addButton(ufoButton);
        ufoButton->setObjectName(QString::fromUtf8("ufoButton"));
        sizePolicy.setHeightForWidth(ufoButton->sizePolicy().hasHeightForWidth());
        ufoButton->setSizePolicy(sizePolicy);
        ufoButton->setFont(font2);
        ufoButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(ufoButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        spaceShipLabel = new QLabel(layoutWidget2);
        spaceShipLabel->setObjectName(QString::fromUtf8("spaceShipLabel"));
        sizePolicy.setHeightForWidth(spaceShipLabel->sizePolicy().hasHeightForWidth());
        spaceShipLabel->setSizePolicy(sizePolicy);
        spaceShipLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/spaceship_45x31.png")));

        horizontalLayout_2->addWidget(spaceShipLabel);

        tankLabel = new QLabel(layoutWidget2);
        tankLabel->setObjectName(QString::fromUtf8("tankLabel"));
        sizePolicy.setHeightForWidth(tankLabel->sizePolicy().hasHeightForWidth());
        tankLabel->setSizePolicy(sizePolicy);
        tankLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/tank_sprite_26x50.png")));

        horizontalLayout_2->addWidget(tankLabel);

        ufoLabel = new QLabel(layoutWidget2);
        ufoLabel->setObjectName(QString::fromUtf8("ufoLabel"));
        sizePolicy.setHeightForWidth(ufoLabel->sizePolicy().hasHeightForWidth());
        ufoLabel->setSizePolicy(sizePolicy);
        ufoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/ufo_sprite_50x50.png")));

        horizontalLayout_2->addWidget(ufoLabel);


        verticalLayout_4->addLayout(horizontalLayout_2);

        layoutWidget3 = new QWidget(MainMenuDialog);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 80, 631, 51));
        verticalLayout_2 = new QVBoxLayout(layoutWidget3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        playerNameLabel = new QLabel(layoutWidget3);
        playerNameLabel->setObjectName(QString::fromUtf8("playerNameLabel"));
        sizePolicy.setHeightForWidth(playerNameLabel->sizePolicy().hasHeightForWidth());
        playerNameLabel->setSizePolicy(sizePolicy);
        playerNameLabel->setFont(font1);
        playerNameLabel->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(playerNameLabel);

        playerNameEdit = new QLineEdit(layoutWidget3);
        playerNameEdit->setObjectName(QString::fromUtf8("playerNameEdit"));
        playerNameEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));

        verticalLayout_2->addWidget(playerNameEdit);

        layoutWidget4 = new QWidget(MainMenuDialog);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(310, 450, 344, 26));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        startButton = new QPushButton(layoutWidget4);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy1);
        startButton->setFont(font);
        startButton->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 255, 197)\n"
""));

        horizontalLayout_5->addWidget(startButton);

        exitButton = new QPushButton(layoutWidget4);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        sizePolicy1.setHeightForWidth(exitButton->sizePolicy().hasHeightForWidth());
        exitButton->setSizePolicy(sizePolicy1);
        exitButton->setFont(font);
        exitButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 166, 166)"));

        horizontalLayout_5->addWidget(exitButton);


        horizontalLayout_8->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        settingsButton = new QPushButton(layoutWidget4);
        settingsButton->setObjectName(QString::fromUtf8("settingsButton"));
        settingsButton->setFont(font);
        settingsButton->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));

        horizontalLayout_7->addWidget(settingsButton);

        helpButton = new QPushButton(layoutWidget4);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));
        helpButton->setFont(font);
        helpButton->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));

        horizontalLayout_7->addWidget(helpButton);


        horizontalLayout_8->addLayout(horizontalLayout_7);

        layoutWidget5 = new QWidget(MainMenuDialog);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 10, 631, 61));
        verticalLayout_3 = new QVBoxLayout(layoutWidget5);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        mainHeaderLabel = new QLabel(layoutWidget5);
        mainHeaderLabel->setObjectName(QString::fromUtf8("mainHeaderLabel"));
        sizePolicy.setHeightForWidth(mainHeaderLabel->sizePolicy().hasHeightForWidth());
        mainHeaderLabel->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        mainHeaderLabel->setFont(font3);
        mainHeaderLabel->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(mainHeaderLabel);

        subHeaderLabel = new QLabel(layoutWidget5);
        subHeaderLabel->setObjectName(QString::fromUtf8("subHeaderLabel"));
        sizePolicy.setHeightForWidth(subHeaderLabel->sizePolicy().hasHeightForWidth());
        subHeaderLabel->setSizePolicy(sizePolicy);
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(false);
        font4.setWeight(50);
        subHeaderLabel->setFont(font4);
        subHeaderLabel->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(subHeaderLabel);

        pushButton = new QPushButton(MainMenuDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 450, 80, 22));
        pushButton->setFont(font);

        retranslateUi(MainMenuDialog);

        QMetaObject::connectSlotsByName(MainMenuDialog);
    } // setupUi

    void retranslateUi(QDialog *MainMenuDialog)
    {
        MainMenuDialog->setWindowTitle(QCoreApplication::translate("MainMenuDialog", "Main Menu", nullptr));
        erronousInputLabel->setText(QString());
        projectileTypeLabel->setText(QCoreApplication::translate("MainMenuDialog", "Projectile type:", nullptr));
        fireballButton->setText(QCoreApplication::translate("MainMenuDialog", "Fireball", nullptr));
        missileButton->setText(QCoreApplication::translate("MainMenuDialog", "Missile", nullptr));
        laserButton->setText(QCoreApplication::translate("MainMenuDialog", "Laser", nullptr));
        fireballLabel->setText(QString());
        missileLabel->setText(QString());
        laserLabel->setText(QString());
        playerTypeLabel->setText(QCoreApplication::translate("MainMenuDialog", "Player type:", nullptr));
        spaceshipButton->setText(QCoreApplication::translate("MainMenuDialog", "Spaceship", nullptr));
        tankButton->setText(QCoreApplication::translate("MainMenuDialog", "Tank", nullptr));
        ufoButton->setText(QCoreApplication::translate("MainMenuDialog", "UFO", nullptr));
        spaceShipLabel->setText(QString());
        tankLabel->setText(QString());
        ufoLabel->setText(QString());
        playerNameLabel->setText(QCoreApplication::translate("MainMenuDialog", "Player name:", nullptr));
        startButton->setText(QCoreApplication::translate("MainMenuDialog", "Start", nullptr));
        exitButton->setText(QCoreApplication::translate("MainMenuDialog", "Exit", nullptr));
        settingsButton->setText(QCoreApplication::translate("MainMenuDialog", "Settings", nullptr));
        helpButton->setText(QCoreApplication::translate("MainMenuDialog", "Help", nullptr));
        mainHeaderLabel->setText(QCoreApplication::translate("MainMenuDialog", "Welcome to BUSDESTROYER 2000!", nullptr));
        subHeaderLabel->setText(QCoreApplication::translate("MainMenuDialog", "Please set the following info down below to start playing.", nullptr));
        pushButton->setText(QCoreApplication::translate("MainMenuDialog", "GameOver", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenuDialog: public Ui_MainMenuDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENUDIALOG_H
