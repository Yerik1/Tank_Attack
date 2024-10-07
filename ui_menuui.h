/********************************************************************************
** Form generated from reading UI file 'menuinicialXjQOFe.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MENUINICIALXJQOFE_H
#define MENUINICIALXJQOFE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuInicial
{
public:
    QWidget *centralwidget;
    QLabel *LblTitle;
    QPushButton *BtnRules;
    QPushButton *BtnStart;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MenuInicial)
    {
        if (MenuInicial->objectName().isEmpty())
            MenuInicial->setObjectName(QString::fromUtf8("MenuInicial"));
        MenuInicial->resize(800, 600);
        MenuInicial->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 128, 0)"));
        centralwidget = new QWidget(MenuInicial);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        LblTitle = new QLabel(centralwidget);
        LblTitle->setObjectName(QString::fromUtf8("LblTitle"));
        LblTitle->setGeometry(QRect(170, 0, 471, 151));
        QFont font;
        font.setPointSize(45);
        font.setBold(true);
        font.setWeight(75);
        LblTitle->setFont(font);
        LblTitle->setAlignment(Qt::AlignCenter);
        BtnRules = new QPushButton(centralwidget);
        BtnRules->setObjectName(QString::fromUtf8("BtnRules"));
        BtnRules->setGeometry(QRect(320, 340, 171, 71));
        BtnRules->setStyleSheet(QString::fromUtf8("background-color : rgb(26, 95, 180)"));
        BtnStart = new QPushButton(centralwidget);
        BtnStart->setObjectName(QString::fromUtf8("BtnStart"));
        BtnStart->setGeometry(QRect(320, 230, 171, 71));
        BtnStart->setStyleSheet(QString::fromUtf8("background-color : rgb(26, 95, 180)"));
        MenuInicial->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MenuInicial);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MenuInicial->setStatusBar(statusbar);
        menubar = new QMenuBar(MenuInicial);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MenuInicial->setMenuBar(menubar);

        retranslateUi(MenuInicial);

        QMetaObject::connectSlotsByName(MenuInicial);
    } // setupUi

    void retranslateUi(QMainWindow *MenuInicial)
    {
        MenuInicial->setWindowTitle(QCoreApplication::translate("MenuInicial", "MainWindow", nullptr));
        LblTitle->setText(QCoreApplication::translate("MenuInicial", "TANK ATTACK!!!", nullptr));
        BtnRules->setText(QCoreApplication::translate("MenuInicial", "Reglas y Controles", nullptr));
        BtnStart->setText(QCoreApplication::translate("MenuInicial", "Comenzar Partida", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuInicial: public Ui_MenuInicial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MENUINICIALXJQOFE_H
