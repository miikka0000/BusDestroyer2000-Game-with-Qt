/********************************************************************************
** Form generated from reading UI file 'gameoverdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVERDIALOG_H
#define UI_GAMEOVERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GameOverDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *pointsLabel;
    QLabel *highScoresHeaderLabel;
    QTextBrowser *topscoreWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *playAgainButton;
    QPushButton *gameOverCloseButton;
    QPushButton *statsButton;

    void setupUi(QDialog *GameOverDialog)
    {
        if (GameOverDialog->objectName().isEmpty())
            GameOverDialog->setObjectName(QString::fromUtf8("GameOverDialog"));
        GameOverDialog->resize(400, 300);
        GameOverDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 222, 255);"));
        verticalLayout_2 = new QVBoxLayout(GameOverDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pointsLabel = new QLabel(GameOverDialog);
        pointsLabel->setObjectName(QString::fromUtf8("pointsLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pointsLabel->sizePolicy().hasHeightForWidth());
        pointsLabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        pointsLabel->setFont(font);
        pointsLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(pointsLabel);


        verticalLayout->addLayout(horizontalLayout_2);

        highScoresHeaderLabel = new QLabel(GameOverDialog);
        highScoresHeaderLabel->setObjectName(QString::fromUtf8("highScoresHeaderLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(highScoresHeaderLabel->sizePolicy().hasHeightForWidth());
        highScoresHeaderLabel->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(11);
        highScoresHeaderLabel->setFont(font1);
        highScoresHeaderLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(highScoresHeaderLabel);


        verticalLayout_2->addLayout(verticalLayout);

        topscoreWidget = new QTextBrowser(GameOverDialog);
        topscoreWidget->setObjectName(QString::fromUtf8("topscoreWidget"));
        topscoreWidget->setFont(font1);

        verticalLayout_2->addWidget(topscoreWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        playAgainButton = new QPushButton(GameOverDialog);
        playAgainButton->setObjectName(QString::fromUtf8("playAgainButton"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        playAgainButton->setFont(font2);
        playAgainButton->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));

        horizontalLayout->addWidget(playAgainButton);

        gameOverCloseButton = new QPushButton(GameOverDialog);
        gameOverCloseButton->setObjectName(QString::fromUtf8("gameOverCloseButton"));
        gameOverCloseButton->setFont(font2);
        gameOverCloseButton->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));

        horizontalLayout->addWidget(gameOverCloseButton);

        statsButton = new QPushButton(GameOverDialog);
        statsButton->setObjectName(QString::fromUtf8("statsButton"));
        statsButton->setFont(font2);
        statsButton->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));

        horizontalLayout->addWidget(statsButton);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(GameOverDialog);

        QMetaObject::connectSlotsByName(GameOverDialog);
    } // setupUi

    void retranslateUi(QDialog *GameOverDialog)
    {
        GameOverDialog->setWindowTitle(QCoreApplication::translate("GameOverDialog", "Dialog", nullptr));
        pointsLabel->setText(QCoreApplication::translate("GameOverDialog", "player points", nullptr));
        highScoresHeaderLabel->setText(QCoreApplication::translate("GameOverDialog", "Top10 High Scores:", nullptr));
        playAgainButton->setText(QCoreApplication::translate("GameOverDialog", "Play Again", nullptr));
        gameOverCloseButton->setText(QCoreApplication::translate("GameOverDialog", "Close", nullptr));
        statsButton->setText(QCoreApplication::translate("GameOverDialog", "Statistics", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameOverDialog: public Ui_GameOverDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVERDIALOG_H
