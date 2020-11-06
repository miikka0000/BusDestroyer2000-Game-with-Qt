/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingsDialog
{
public:
    QLabel *settingsHeaderLabel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveSettingsButton;
    QPushButton *backToMainButton;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *chooseTimeLabel;
    QComboBox *timeComboBox;
    QVBoxLayout *verticalLayout_7;
    QCheckBox *musicsOnCheckBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *musicsOnLabel;
    QLabel *musicsOffLabel;

    void setupUi(QDialog *settingsDialog)
    {
        if (settingsDialog->objectName().isEmpty())
            settingsDialog->setObjectName(QString::fromUtf8("settingsDialog"));
        settingsDialog->resize(400, 300);
        settingsDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 222, 255);"));
        settingsHeaderLabel = new QLabel(settingsDialog);
        settingsHeaderLabel->setObjectName(QString::fromUtf8("settingsHeaderLabel"));
        settingsHeaderLabel->setGeometry(QRect(20, 20, 371, 20));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        settingsHeaderLabel->setFont(font);
        settingsHeaderLabel->setAlignment(Qt::AlignCenter);
        widget = new QWidget(settingsDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(230, 270, 168, 24));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        saveSettingsButton = new QPushButton(widget);
        saveSettingsButton->setObjectName(QString::fromUtf8("saveSettingsButton"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        saveSettingsButton->setFont(font1);
        saveSettingsButton->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));

        horizontalLayout->addWidget(saveSettingsButton);

        backToMainButton = new QPushButton(widget);
        backToMainButton->setObjectName(QString::fromUtf8("backToMainButton"));
        backToMainButton->setFont(font1);
        backToMainButton->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));

        horizontalLayout->addWidget(backToMainButton);

        widget1 = new QWidget(settingsDialog);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(20, 80, 361, 88));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        chooseTimeLabel = new QLabel(widget1);
        chooseTimeLabel->setObjectName(QString::fromUtf8("chooseTimeLabel"));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        chooseTimeLabel->setFont(font2);

        horizontalLayout_2->addWidget(chooseTimeLabel);

        timeComboBox = new QComboBox(widget1);
        timeComboBox->addItem(QString());
        timeComboBox->addItem(QString());
        timeComboBox->addItem(QString());
        timeComboBox->setObjectName(QString::fromUtf8("timeComboBox"));
        timeComboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));

        horizontalLayout_2->addWidget(timeComboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        musicsOnCheckBox = new QCheckBox(widget1);
        musicsOnCheckBox->setObjectName(QString::fromUtf8("musicsOnCheckBox"));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        musicsOnCheckBox->setFont(font3);

        verticalLayout_7->addWidget(musicsOnCheckBox);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        musicsOnLabel = new QLabel(widget1);
        musicsOnLabel->setObjectName(QString::fromUtf8("musicsOnLabel"));
        musicsOnLabel->setStyleSheet(QString::fromUtf8(""));
        musicsOnLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/souds_on.png")));

        horizontalLayout_6->addWidget(musicsOnLabel);

        musicsOffLabel = new QLabel(widget1);
        musicsOffLabel->setObjectName(QString::fromUtf8("musicsOffLabel"));
        musicsOffLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/souds_off.png")));

        horizontalLayout_6->addWidget(musicsOffLabel);


        verticalLayout_7->addLayout(horizontalLayout_6);


        verticalLayout->addLayout(verticalLayout_7);


        retranslateUi(settingsDialog);

        QMetaObject::connectSlotsByName(settingsDialog);
    } // setupUi

    void retranslateUi(QDialog *settingsDialog)
    {
        settingsDialog->setWindowTitle(QCoreApplication::translate("settingsDialog", "Dialog", nullptr));
        settingsHeaderLabel->setText(QCoreApplication::translate("settingsDialog", "SETTINGS", nullptr));
        saveSettingsButton->setText(QCoreApplication::translate("settingsDialog", "Save", nullptr));
        backToMainButton->setText(QCoreApplication::translate("settingsDialog", "Back", nullptr));
        chooseTimeLabel->setText(QCoreApplication::translate("settingsDialog", "Game Duration (in minutes):", nullptr));
        timeComboBox->setItemText(0, QCoreApplication::translate("settingsDialog", "1 min", nullptr));
        timeComboBox->setItemText(1, QCoreApplication::translate("settingsDialog", "2 min", nullptr));
        timeComboBox->setItemText(2, QCoreApplication::translate("settingsDialog", "3 min", nullptr));

        musicsOnCheckBox->setText(QCoreApplication::translate("settingsDialog", "Musics ON/OFF", nullptr));
        musicsOnLabel->setText(QString());
        musicsOffLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class settingsDialog: public Ui_settingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
