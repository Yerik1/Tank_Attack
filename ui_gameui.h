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
    QWidget *VidaRojo1;
    QWidget *VidaRojo2;
    QWidget *VidaAzul1;
    QWidget *VidaAzul2;
    QWidget *VidaAmarillo1;
    QWidget *VidaAmarillo2;
    QWidget *VidaCeleste1;
    QWidget *VidaCeleste2;
    QLabel *VidaRojo1L;
    QLabel *VidaAzul1L;
    QLabel *VidaAmarillo1L;
    QLabel *VidaCeleste1L;
    QLabel *VidaRojo2L;
    QLabel *VidaAzul2L;
    QLabel *VidaAmarillo2L;
    QLabel *VidaCeleste2L;
    QTableWidget *Tablero;
    QWidget *widget;
    QWidget *TRojo1;
    QWidget *TRojo2;
    QWidget *TAzul1;
    QWidget *TAzul2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *PowerUPP1;
    QLabel *PowerUpP2;
    QLabel *Contador;
    QLabel *Turno;
    QWidget *TAmarillo1;
    QWidget *TAmarillo2;
    QWidget *TCeleste1;
    QWidget *TCeleste2;
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
        VidaRojo1 = new QWidget(centralwidget);
        VidaRojo1->setObjectName(QString::fromUtf8("VidaRojo1"));
        VidaRojo1->setGeometry(QRect(80, 690, 80, 80));
        VidaRojo1->setStyleSheet(QString::fromUtf8("background-image:url(../Imagenes/Rojo.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: cover;"));
        VidaRojo2 = new QWidget(centralwidget);
        VidaRojo2->setObjectName(QString::fromUtf8("VidaRojo2"));
        VidaRojo2->setGeometry(QRect(80, 740, 80, 80));
        VidaRojo2->setStyleSheet(QString::fromUtf8("background-image:url(../Imagenes/Rojo.png);\n"
    "background-repeat: no-repeat;\n"
    "background-position: center;\n"
    "background-size: cover;"));
        VidaAzul1 = new QWidget(centralwidget);
        VidaAzul1->setObjectName(QString::fromUtf8("VidaAzul1"));
        VidaAzul1->setGeometry(QRect(280, 690, 80, 80));
        VidaAzul1->setStyleSheet(QString::fromUtf8("background-image:url(../Imagenes/Azul.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: cover;"));
        VidaAzul2 = new QWidget(centralwidget);
        VidaAzul2->setObjectName(QString::fromUtf8("VidaAzul2"));
        VidaAzul2->setGeometry(QRect(280, 740, 80, 80));
        VidaAzul2->setStyleSheet(QString::fromUtf8("background-image:url(../Imagenes/Azul.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: cover;"));
        VidaAmarillo1 = new QWidget(centralwidget);
        VidaAmarillo1->setObjectName(QString::fromUtf8("VidaAmarillo1"));
        VidaAmarillo1->setGeometry(QRect(630, 690, 80, 80));
        VidaAmarillo1->setStyleSheet(QString::fromUtf8("background-image:url(../Imagenes/Amarillo.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: cover;"));
        VidaAmarillo2 = new QWidget(centralwidget);
        VidaAmarillo2->setObjectName(QString::fromUtf8("VidaAmarillo2"));
        VidaAmarillo2->setGeometry(QRect(630, 740, 80, 80));
        VidaAmarillo2->setStyleSheet(QString::fromUtf8("background-image:url(../Imagenes/Amarillo.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: cover;"));
        VidaCeleste1 = new QWidget(centralwidget);
        VidaCeleste1->setObjectName(QString::fromUtf8("VidaCeleste1"));
        VidaCeleste1->setGeometry(QRect(840, 690, 80, 80));
        VidaCeleste1->setStyleSheet(QString::fromUtf8("background-image:url(../Imagenes/Celeste.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: cover;"));
        VidaCeleste2 = new QWidget(centralwidget);
        VidaCeleste2->setObjectName(QString::fromUtf8("VidaCeleste2"));
        VidaCeleste2->setGeometry(QRect(840, 740, 80, 80));
        VidaCeleste2->setStyleSheet(QString::fromUtf8("background-image:url(../Imagenes/Celeste.png);\n"
    "background-repeat: no-repeat;\n"
    "background-position: center;\n"
    "background-size: cover;"));
        VidaRojo1L = new QLabel(centralwidget);
        VidaRojo1L->setObjectName(QString::fromUtf8("VidaRojo1L"));
        VidaRojo1L->setGeometry(QRect(190, 700, 66, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu Sans Mono"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        VidaRojo1L->setFont(font1);
        VidaRojo1L->setAlignment(Qt::AlignCenter);

        VidaRojo2L = new QLabel(centralwidget);
        VidaRojo2L->setObjectName(QString::fromUtf8("VidaRojo2L"));
        VidaRojo2L->setGeometry(QRect(190, 750, 66, 61));
        VidaRojo2L->setFont(font1);
        VidaRojo2L->setAlignment(Qt::AlignCenter);

        VidaAzul1L = new QLabel(centralwidget);
        VidaAzul1L = new QLabel(centralwidget);
        VidaAzul1L->setObjectName(QString::fromUtf8("VidaAzul1L"));
        VidaAzul1L->setGeometry(QRect(380, 700, 66, 61));
        VidaAzul1L->setFont(font1);
        VidaAzul1L->setAlignment(Qt::AlignCenter);

        VidaAzul2L = new QLabel(centralwidget);
        VidaAzul2L = new QLabel(centralwidget);
        VidaAzul2L->setObjectName(QString::fromUtf8("VidaAzul2L"));
        VidaAzul2L->setGeometry(QRect(380, 750, 66, 61));
        VidaAzul2L->setFont(font1);
        VidaAzul2L->setAlignment(Qt::AlignCenter);

        VidaAmarillo1L = new QLabel(centralwidget);
        VidaAmarillo1L->setObjectName(QString::fromUtf8("VidaAmarillo1L"));
        VidaAmarillo1L->setGeometry(QRect(740, 700, 66, 61));
        VidaAmarillo1L->setFont(font1);
        VidaAmarillo1L->setAlignment(Qt::AlignCenter);

        VidaAmarillo2L = new QLabel(centralwidget);
        VidaAmarillo2L->setObjectName(QString::fromUtf8("VidaAmarillo2L"));
        VidaAmarillo2L->setGeometry(QRect(740, 750, 66, 61));
        VidaAmarillo2L->setFont(font1);
        VidaAmarillo2L->setAlignment(Qt::AlignCenter);

        VidaCeleste1L = new QLabel(centralwidget);
        VidaCeleste1L->setObjectName(QString::fromUtf8("VidaCeleste1L"));
        VidaCeleste1L->setGeometry(QRect(950, 700, 66, 61));
        VidaCeleste1L->setFont(font1);
        VidaCeleste1L->setAlignment(Qt::AlignCenter);

        VidaCeleste2L = new QLabel(centralwidget);
        VidaCeleste2L->setObjectName(QString::fromUtf8("VidaCeleste2L"));
        VidaCeleste2L->setGeometry(QRect(950, 750, 66, 61));
        VidaCeleste2L->setFont(font1);
        VidaCeleste2L->setAlignment(Qt::AlignCenter);

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

        TRojo1 = new QWidget(centralwidget);
        TRojo1->setObjectName(QString::fromUtf8("TRojo1"));
        TRojo1->setGeometry(QRect(100+23*7, 230+23*7, 23, 23));
        TRojo1->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"background-image:url(../Imagenes/Rojo.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: cover;"));
        TRojo2 = new QWidget(centralwidget);
        TRojo2->setObjectName(QString::fromUtf8("TRojo2"));
        TRojo2->setGeometry(QRect(100+23*7, 230+23*9, 23, 23));
        TRojo2->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"background-image:url(../Imagenes/Rojo.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: cover;"));
        TAzul1 = new QWidget(centralwidget);
        TAzul1->setObjectName(QString::fromUtf8("TAzul1"));
        TAzul1->setGeometry(QRect(100+23*7, 230+23*12, 23, 23));
        TAzul1->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"background-image:url(../Imagenes/Azul.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: cover;"));
        TAzul2 = new QWidget(centralwidget);
        TAzul2->setObjectName(QString::fromUtf8("TAzul2"));
        TAzul2->setGeometry(QRect(100+23*7, 230+23*14, 23, 23));
        TAzul2->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
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
        PowerUPP1 = new QLabel(centralwidget);
        PowerUPP1->setObjectName(QString::fromUtf8("PowerUPP1"));
        PowerUPP1->setGeometry(QRect(220, 80, 60, 60));
        PowerUPP1->setAutoFillBackground(false);
        PowerUPP1->setStyleSheet(QString::fromUtf8("\n"
"background-size: contain;\n"
"background-repeat: no-repeat;\n"
"background-position: center;"));
        PowerUpP2 = new QLabel(centralwidget);
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
        TAmarillo1 = new QWidget(centralwidget);
        TAmarillo1->setObjectName(QString::fromUtf8("TAmarillo1"));
        TAmarillo1->setGeometry(QRect(100+23*32, 230+23*7, 23, 23));
        TAmarillo1->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"background-image:url(../Imagenes/Amarillo.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: cover;"));
        TAmarillo2 = new QWidget(centralwidget);
        TAmarillo2->setObjectName(QString::fromUtf8("TAmarillo2"));
        TAmarillo2->setGeometry(QRect(100+23*32, 230+23*9, 23, 23));
        TAmarillo2->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
    "background-image:url(../Imagenes/Amarillo.png);\n"
    "background-repeat: no-repeat;\n"
    "background-position: center;\n"
    "background-size: cover;"));
        TCeleste1 = new QWidget(centralwidget);
        TCeleste1->setObjectName(QString::fromUtf8("TCeleste1"));
        TCeleste1->setGeometry(QRect(100+23*32, 230+23*12, 23, 23));
        TCeleste1->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"background-image:url(../Imagenes/Celeste.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: cover;"));
        TCeleste2 = new QWidget(centralwidget);
        TCeleste2->setObjectName(QString::fromUtf8("TCeleste2"));
        TCeleste2->setGeometry(QRect(100+23*32, 230+23*14, 23, 23));
        TCeleste2->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"background-image:url(../Imagenes/Celeste.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: cover;"));
        MainWindow->setCentralWidget(centralwidget);

        Tablero->raise();
        Titulo->raise();
        VidaRojo1->raise();
        VidaAzul1->raise();
        VidaAmarillo1->raise();
        VidaCeleste1->raise();
        VidaRojo2->raise();
        VidaAzul2->raise();
        VidaAmarillo2->raise();
        VidaCeleste2->raise();
        VidaRojo1L->raise();
        VidaAzul1L->raise();
        VidaAmarillo1L->raise();
        VidaCeleste1L->raise();
        VidaRojo2L->raise();
        VidaAzul2L->raise();
        VidaAmarillo2L->raise();
        VidaCeleste2L->raise();
        label_6->raise();
        label_7->raise();
        PowerUPP1->raise();
        PowerUpP2->raise();
        Contador->raise();
        Turno->raise();
        TRojo1->raise();
        TAzul1->raise();
        TAmarillo1->raise();
        TCeleste1->raise();
        TRojo2->raise();
        TAzul2->raise();
        TAmarillo2->raise();
        TCeleste2->raise();
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
        VidaRojo1L->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        VidaAzul1L->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        VidaAmarillo1L->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        VidaCeleste1L->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        VidaRojo2L->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        VidaAzul2L->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        VidaAmarillo2L->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        VidaCeleste2L->setText(QCoreApplication::translate("MainWindow", "4", nullptr));

        const bool __sortingEnabled = Tablero->isSortingEnabled();
        Tablero->setSortingEnabled(false);
        Tablero->setSortingEnabled(__sortingEnabled);

        label_6->setText(QCoreApplication::translate("MainWindow", "Siguiente Power-Up", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Siguiente Power-Up", nullptr));
        Contador->setText(QCoreApplication::translate("MainWindow", "0:00", nullptr));
        Turno->setText(QCoreApplication::translate("MainWindow", "Turno jugador X", nullptr));
        Contador->setText(QCoreApplication::translate("MainWindow", "5:00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif //GAMEUI_H
