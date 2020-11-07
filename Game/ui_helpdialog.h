/********************************************************************************
** Form generated from reading UI file 'helpdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPDIALOG_H
#define UI_HELPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_helpDialog
{
public:
    QPushButton *closeHelpButton;
    QTextBrowser *helpTextBrowser;

    void setupUi(QDialog *helpDialog)
    {
        if (helpDialog->objectName().isEmpty())
            helpDialog->setObjectName(QString::fromUtf8("helpDialog"));
        helpDialog->resize(466, 307);
        closeHelpButton = new QPushButton(helpDialog);
        closeHelpButton->setObjectName(QString::fromUtf8("closeHelpButton"));
        closeHelpButton->setGeometry(QRect(430, 0, 20, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        closeHelpButton->setFont(font);
        closeHelpButton->setStyleSheet(QString::fromUtf8("background-image: url(:/images/exitButton.png);\n"
""));
        helpTextBrowser = new QTextBrowser(helpDialog);
        helpTextBrowser->setObjectName(QString::fromUtf8("helpTextBrowser"));
        helpTextBrowser->setGeometry(QRect(0, 0, 471, 311));
        helpTextBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 222, 255);"));
        helpTextBrowser->raise();
        closeHelpButton->raise();

        retranslateUi(helpDialog);

        QMetaObject::connectSlotsByName(helpDialog);
    } // setupUi

    void retranslateUi(QDialog *helpDialog)
    {
        helpDialog->setWindowTitle(QCoreApplication::translate("helpDialog", "Dialog", nullptr));
        closeHelpButton->setText(QString());
        helpTextBrowser->setHtml(QCoreApplication::translate("helpDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">		</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Game Instructions:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:600;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; "
                        "text-indent:0px;\"><span style=\" font-size:9pt;\">Welcome to </span><span style=\" font-size:9pt; font-weight:600;\">BusDestoryer 2000</span><span style=\" font-size:9pt;\">! The game's </span><span style=\" font-size:9pt; font-style:italic;\">objective</span><span style=\" font-size:9pt;\"> is to collect as many points as possible in a predetermined time slot (1-3 minutes) by shooting the evil Nysse-buses and the passengers in the game map which represents Tampere City Center. In the actual game map </span><span style=\" font-size:9pt; font-style:italic;\">Stops </span><span style=\" font-size:9pt;\">are marked as </span><span style=\" font-size:9pt; color:#ff0000;\">red </span><span style=\" font-size:9pt; color:#000000;\">flags, </span><span style=\" font-size:9pt; font-style:italic; color:#000000;\">passengers</span><span style=\" font-size:9pt; color:#000000;\"> with </span><span style=\" font-size:9pt; color:#aa55ff;\">violet </span><span style=\" font-size:9pt; color:#000000;\">characters, </span><span"
                        " style=\" font-size:9pt; font-style:italic; color:#000000;\">Nysse-buses</span><span style=\" font-size:9pt; color:#000000;\"> with </span><span style=\" font-size:9pt; color:#0000ff;\">blue </span><span style=\" font-size:9pt; color:#000000;\">rectangles and randomly spawning bonus gems with </span><span style=\" font-size:9pt; color:#ff0000;\">red </span><span style=\" font-size:9pt; color:#000000;\">diamonds.</span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">Your points collected and the time left is shown on the Main Game Window top panel, when you start the game. Red bonus gems spawn in the game map once in a while and if you manage to collect them (by moving into the gems location"
                        " or by shooting it), you get 10 points added to your score. Also if you manage to kill a passanger or destroy a Nysse-bus, you will get 10 points added into your game score point count.</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\"> </span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">The game is designed to </span><span style=\" font-size:9pt; font-style:italic;\">end</span><span style=\" font-size:9pt;\"> when you either run out of time. You will be given your score when the game ends. When the game ends, there will prompt a GameOverDialog, in which you'll see top10 ScoreBoard. Furthermore, from GameOverDialog you can access your ingame </span><span style=\" font-size:9pt; font-style:italic;\">Statistics</span><span style=\" font-size:9pt;"
                        "\"> by pressing the &quot;Statisctics&quot; -button.</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Player controls:</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:600;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">- </span><span style=\" font-size:9pt; font-style:italic;\">Arrow Keys</span><span style=\" font-size:9pt;\"> for moving in four different directions (Left, Right, Up and Down)</"
                        "span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">- </span><span style=\" font-size:9pt; font-style:italic;\">Space Bar</span><span style=\" font-size:9pt;\"> for shooting</span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">- </span><span style=\" font-size:9pt; font-style:italic;\">Plus</span><span style=\" font-size:9pt;\"> (+) Key for increasing player velocity, "
                        "</span><span style=\" font-size:9pt; font-style:italic;\">Minus</span><span style=\" font-size:9pt;\"> (-) Key for decreasing player velocity </span><span style=\" font-size:9pt; font-style:italic;\">within reasonable limits</span><span style=\" font-size:9pt;\"> (you can't increase or decrease your velocity infinitely)</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/images/controlsPicture.png\" /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
""
                        "<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Player Configuration Options:</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:600;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">Player is able to choose from 3 different player types: 1) </span><span style=\" font-size:9pt; font-style:italic;\">Spaceship</span><span style=\" font-size:9pt;\">, 2) </span><span style=\" font-size:9pt; font-style:italic;\">Tank<"
                        "/span><span style=\" font-size:9pt;\"> or 3) </span><span style=\" font-size:9pt; font-style:italic;\">UFO</span><span style=\" font-size:9pt;\">. Furthermore, you can pick from 3 projectile types: 1) </span><span style=\" font-size:9pt; font-style:italic;\">Fireball</span><span style=\" font-size:9pt;\">, 2) </span><span style=\" font-size:9pt; font-style:italic;\">Missile</span><span style=\" font-size:9pt;\"> or 3) </span><span style=\" font-size:9pt; font-style:italic;\">Laser</span><span style=\" font-size:9pt;\">. There is no restriction on how to mix and match these player-projectile combinations. We also encourage you to set a nickname for your player since setting a player name, and choosing player and projectile type are prequisite for starting and playing the game. </span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px;"
                        " margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Settings:</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	</p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">Player has the opportunity to set the shooting sound effects on by checking the &quot;MUSICS ON / OFF&quot; checkbox in the </span><span style=\" font-size:9pt; font-style:italic;\">Settings</span><span style=\" font-size:9pt;\">. Beware that the sound effects will propably cause some considerable latency on the gameplay and therefore the sound effects are disabled as a default. All the different projectile types have an unique sound effect.</span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margi"
                        "n-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">In the </span><span style=\" font-size:9pt; font-style:italic;\">Settings </span><span style=\" font-size:9pt;\">you can also change the Game duration (1 to 3 minutes). The default game timer is set to 2 minute if you don't make any changes. Remember to press </span><span style=\" font-size:9pt; font-style:italic;\">Save </span><span style=\" font-size:9pt;\">button in the settings dialog if you wish to save your options since otherwise your sound effects and game duration are set to the default values automatically (disabled and 2 minutes).</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class helpDialog: public Ui_helpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPDIALOG_H
