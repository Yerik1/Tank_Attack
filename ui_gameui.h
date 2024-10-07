//
// Created by yerik on 9/29/24.
//

#ifndef GAMEUI_H
#define GAMEUI_H

#include <QMainWindow>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *Titulo;
    QWidget *widget_2;
    QWidget *widget_3;
    QWidget *widget_4;
    QWidget *widget_5;
    QLabel *VidaRojo;
    QLabel *VidaAzul;
    QLabel *VidaAmarillo;
    QLabel *VidaCeleste;
    QTableWidget *Tablero;
    QWidget *widget;
    QWidget *TRojo;
    QWidget *TAzul;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *PowerUPP1;
    QWidget *PowerUpP2;
    QLabel *Contador;
    QLabel *Turno;
    QWidget *TAmarillo;
    QWidget *TCeleste;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1131, 830);
        MainWindow->setCursor(QCursor(Qt::PointingHandCursor));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 128, 0)"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Titulo = new QLabel(centralwidget);
        Titulo->setObjectName(QString::fromUtf8("Titulo"));
        Titulo->setGeometry(QRect(410, 20, 291, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Sans Mono"));
        font.setPointSize(25);
        font.setBold(true);
        font.setWeight(75);
        Titulo->setFont(font);
        Titulo->setLayoutDirection(Qt::LeftToRight);
        Titulo->setTextFormat(Qt::PlainText);
        Titulo->setAlignment(Qt::AlignCenter);
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(80, 690, 81, 80));
        widget_2->setStyleSheet(QString::fromUtf8("background-image:url(../Imagenes/Rojo.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: cover;"));
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(280, 690, 81, 80));
        widget_3->setStyleSheet(QString::fromUtf8("background-image:url(../Imagenes/Azul.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: cover;"));
        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(630, 690, 81, 80));
        widget_4->setStyleSheet(QString::fromUtf8("background-image:url(../Imagenes/Amarillo.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: cover;"));
        widget_5 = new QWidget(centralwidget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(840, 690, 81, 80));
        widget_5->setStyleSheet(QString::fromUtf8("background-image:url(../Imagenes/Celeste.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: cover;"));
        VidaRojo = new QLabel(centralwidget);
        VidaRojo->setObjectName(QString::fromUtf8("VidaRojo"));
        VidaRojo->setGeometry(QRect(190, 700, 66, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu Sans Mono"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        VidaRojo->setFont(font1);
        VidaRojo->setAlignment(Qt::AlignCenter);
        VidaAzul = new QLabel(centralwidget);
        VidaAzul->setObjectName(QString::fromUtf8("VidaAzul"));
        VidaAzul->setGeometry(QRect(380, 700, 66, 61));
        VidaAzul->setFont(font1);
        VidaAzul->setAlignment(Qt::AlignCenter);
        VidaAmarillo = new QLabel(centralwidget);
        VidaAmarillo->setObjectName(QString::fromUtf8("VidaAmarillo"));
        VidaAmarillo->setGeometry(QRect(740, 700, 66, 61));
        VidaAmarillo->setFont(font1);
        VidaAmarillo->setAlignment(Qt::AlignCenter);
        VidaCeleste = new QLabel(centralwidget);
        VidaCeleste->setObjectName(QString::fromUtf8("VidaCeleste"));
        VidaCeleste->setGeometry(QRect(950, 700, 66, 61));
        VidaCeleste->setFont(font1);
        VidaCeleste->setAlignment(Qt::AlignCenter);
        Tablero = new QTableWidget(centralwidget);
        if (Tablero->columnCount() < 40)
            Tablero->setColumnCount(40);
        if (Tablero->rowCount() < 20)
            Tablero->setRowCount(20);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Tablero->setItem(0, 0, __qtablewidgetitem);
        Tablero->setObjectName(QString::fromUtf8("Tablero"));
        Tablero->setGeometry(QRect(100, 230, 920, 460));
        Tablero->setStyleSheet(QString::fromUtf8("background-image: url(../Imagenes/Background.png);"));
        Tablero->setFrameShape(QFrame::NoFrame);
        Tablero->setFrameShadow(QFrame::Plain);
        Tablero->setLineWidth(0);
        Tablero->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Tablero->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Tablero->setShowGrid(false);
        Tablero->setRowCount(20);
        Tablero->setColumnCount(40);
        Tablero->horizontalHeader()->setVisible(false);
        Tablero->horizontalHeader()->setDefaultSectionSize(23);
        Tablero->horizontalHeader()->setHighlightSections(true);
        Tablero->verticalHeader()->setVisible(false);
        Tablero->verticalHeader()->setDefaultSectionSize(23);

        TRojo = new QWidget(centralwidget);
        TRojo->setObjectName(QString::fromUtf8("TRojo"));
        TRojo->setGeometry(QRect(100+23*7, 230+23*7, 23, 23));
        TRojo->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"background-image:url(../Imagenes/Rojo.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: cover;"));
        TAzul = new QWidget(centralwidget);
        TAzul->setObjectName(QString::fromUtf8("TAzul"));
        TAzul->setGeometry(QRect(100+23*7, 230+23*12, 23, 23));
        TAzul->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"background-image:url(../Imagenes/Azul.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: cover;"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(170, 60, 161, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu Sans Mono"));
        font2.setBold(true);
        font2.setWeight(75);
        label_6->setFont(font2);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(780, 60, 151, 19));
        label_7->setFont(font2);
        PowerUPP1 = new QWidget(centralwidget);
        PowerUPP1->setObjectName(QString::fromUtf8("PowerUPP1"));
        PowerUPP1->setGeometry(QRect(220, 80, 60, 60));
        PowerUPP1->setAutoFillBackground(false);
        PowerUPP1->setStyleSheet(QString::fromUtf8("\n"
"background-size: contain;\n"
"background-repeat: no-repeat;\n"
"background-position: center;"));
        PowerUpP2 = new QWidget(centralwidget);
        PowerUpP2->setObjectName(QString::fromUtf8("PowerUpP2"));
        PowerUpP2->setGeometry(QRect(830, 80, 60, 60));
        Contador = new QLabel(centralwidget);
        Contador->setObjectName(QString::fromUtf8("Contador"));
        Contador->setGeometry(QRect(410, 80, 291, 61));
        Contador->setFont(font);
        Contador->setLayoutDirection(Qt::LeftToRight);
        Contador->setTextFormat(Qt::PlainText);
        Contador->setAlignment(Qt::AlignCenter);
        Turno = new QLabel(centralwidget);
        Turno->setObjectName(QString::fromUtf8("Turno"));
        Turno->setGeometry(QRect(410, 160, 291, 61));
        Turno->setFont(font);
        Turno->setLayoutDirection(Qt::LeftToRight);
        Turno->setTextFormat(Qt::PlainText);
        Turno->setAlignment(Qt::AlignCenter);
        TAmarillo = new QWidget(centralwidget);
        TAmarillo->setObjectName(QString::fromUtf8("TAmarillo"));
        TAmarillo->setGeometry(QRect(100+23*32, 230+23*7, 23, 23));
        TAmarillo->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"background-image:url(../Imagenes/Amarillo.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: cover;"));
        TCeleste = new QWidget(centralwidget);
        TCeleste->setObjectName(QString::fromUtf8("TCeleste"));
        TCeleste->setGeometry(QRect(100+23*32, 230+23*12, 23, 23));
        TCeleste->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"background-image:url(../Imagenes/Celeste.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: cover;"));
        MainWindow->setCentralWidget(centralwidget);

        Tablero->raise();
        Titulo->raise();
        widget_2->raise();
        widget_3->raise();
        widget_4->raise();
        widget_5->raise();
        VidaRojo->raise();
        VidaAzul->raise();
        VidaAmarillo->raise();
        VidaCeleste->raise();
        label_6->raise();
        label_7->raise();
        PowerUPP1->raise();
        PowerUpP2->raise();
        Contador->raise();
        Turno->raise();
        TRojo->raise();
        TAzul->raise();
        TAmarillo->raise();
        TCeleste->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setContextMenuPolicy(Qt::DefaultContextMenu);
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Titulo->setText(QCoreApplication::translate("MainWindow", "Tank Attack!", nullptr));
        VidaRojo->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        VidaAzul->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        VidaAmarillo->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        VidaCeleste->setText(QCoreApplication::translate("MainWindow", "2", nullptr));

        const bool __sortingEnabled = Tablero->isSortingEnabled();
        Tablero->setSortingEnabled(false);
        Tablero->setSortingEnabled(__sortingEnabled);

        label_6->setText(QCoreApplication::translate("MainWindow", "Siguiente Power-Up", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Siguiente Power-Up", nullptr));
        Contador->setText(QCoreApplication::translate("MainWindow", "0:00", nullptr));
        Turno->setText(QCoreApplication::translate("MainWindow", "Turno jugador X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif //GAMEUI_H
