/********************************************************************************
** Form generated from reading UI file 'statistisdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTISDIALOG_H
#define UI_STATISTISDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_statistisDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *statsLabel;
    QTextBrowser *statsTextBrowser;
    QHBoxLayout *horizontalLayout;
    QPushButton *playAgainButton;
    QPushButton *exitGameButton;

    void setupUi(QDialog *statistisDialog)
    {
        if (statistisDialog->objectName().isEmpty())
            statistisDialog->setObjectName(QString::fromUtf8("statistisDialog"));
        statistisDialog->resize(400, 300);
        statistisDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 222, 255);"));
        verticalLayout = new QVBoxLayout(statistisDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        statsLabel = new QLabel(statistisDialog);
        statsLabel->setObjectName(QString::fromUtf8("statsLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(statsLabel->sizePolicy().hasHeightForWidth());
        statsLabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        statsLabel->setFont(font);
        statsLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(statsLabel);

        statsTextBrowser = new QTextBrowser(statistisDialog);
        statsTextBrowser->setObjectName(QString::fromUtf8("statsTextBrowser"));
        QFont font1;
        font1.setPointSize(11);
        statsTextBrowser->setFont(font1);
        statsTextBrowser->setAutoFormatting(QTextEdit::AutoNone);

        verticalLayout->addWidget(statsTextBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        playAgainButton = new QPushButton(statistisDialog);
        playAgainButton->setObjectName(QString::fromUtf8("playAgainButton"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        playAgainButton->setFont(font2);
        playAgainButton->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));

        horizontalLayout->addWidget(playAgainButton);

        exitGameButton = new QPushButton(statistisDialog);
        exitGameButton->setObjectName(QString::fromUtf8("exitGameButton"));
        exitGameButton->setFont(font2);
        exitGameButton->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));

        horizontalLayout->addWidget(exitGameButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(statistisDialog);

        QMetaObject::connectSlotsByName(statistisDialog);
    } // setupUi

    void retranslateUi(QDialog *statistisDialog)
    {
        statistisDialog->setWindowTitle(QCoreApplication::translate("statistisDialog", "Dialog", nullptr));
        statsLabel->setText(QCoreApplication::translate("statistisDialog", "Your game Statistics:", nullptr));
        playAgainButton->setText(QCoreApplication::translate("statistisDialog", "Play again", nullptr));
        exitGameButton->setText(QCoreApplication::translate("statistisDialog", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class statistisDialog: public Ui_statistisDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTISDIALOG_H
