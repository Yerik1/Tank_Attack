//
// Created by yerik on 9/29/24.
//
#include "window.h"
#include "ui_gameui.h"
#include <QTableWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QIcon>
#include <QPixmap>
#include <QRandomGenerator>

Window::Window(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), dragging(false), lastSelectedRow(-1), lastSelectedColumn(-1) {
    ui->setupUi(this);

    ui->Tablero->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->Tablero->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->Tablero->setSelectionBehavior(QAbstractItemView::SelectItems);

    // Establecer la geometría y propiedades del tablero
    ui->Tablero->setRowCount(20);
    ui->Tablero->setColumnCount(40);
    ui->Tablero->horizontalHeader()->setVisible(false);
    ui->Tablero->verticalHeader()->setVisible(false);
    ui->Tablero->setShowGrid(false);

    // Inicializar elementos en el tablero
    for (int row = 0; row < 20; ++row) {
        for (int column = 0; column < 40; ++column) {
            QTableWidgetItem *item = new QTableWidgetItem();
            ui->Tablero->setItem(row, column, item);
        }
    }

    // Conectar el evento cellPressed
    connect(ui->Tablero, &QTableWidget::cellPressed, this, &Window::cellPressed);

    // Habilitar la transparencia para el mouse
    ui->Tablero->setAttribute(Qt::WA_TransparentForMouseEvents);
    generateMapBorder();
    generateRandomObstacles();


}

Window::~Window() {
    delete ui;
}

// Método para manejar la selección de la celda
void Window::cellPressed(int row, int column) {
    qDebug() << "Cell pressed:" << row << column; // Mensaje de depuración
    QTableWidgetItem* item = ui->Tablero->item(row, column);
    if (item) {
        ui->Tablero->clearSelection();
        item->setSelected(true);
        lastSelectedRow = row;
        lastSelectedColumn = column;
    }
}

// Manejar el evento de presión del mouse
void Window::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton || event->button() == Qt::RightButton) {
        QPoint pos = ui->Tablero->mapFromGlobal(event->globalPos());
        QTableWidgetItem* item = ui->Tablero->itemAt(pos);
        if (item) {
            cellPressed(item->row(), item->column());
            dragging = true;  // Iniciar el arrastre
        }
    }

    // Llama a la implementación base
    QMainWindow::mousePressEvent(event);
}

// Manejar el evento de liberación del mouse
void Window::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton || event->button() == Qt::RightButton) {
        dragging = false;  // Finalizar el arrastre
    }

    // Llama a la implementación base
    QMainWindow::mouseReleaseEvent(event);
}

// Manejar el evento de movimiento del mouse
void Window::mouseMoveEvent(QMouseEvent *event) {
    if (dragging) {
        return;  // Evita cambiar la selección
    }

    // Llama a la implementación base
    QMainWindow::mouseMoveEvent(event);
}

void Window::generateMapBorder() {
    for (int row = 0; row < 20; ++row) {
        for (int column = 0; column < 40; ++column) {
            QTableWidgetItem *item = new QTableWidgetItem();

            // Solo agregar imágenes a las celdas que no sean la central
            if (row != 0 && column != 0 && row!=19 && column!=39) {
                // Dejar la celda central vacía
                item->setBackground(Qt::transparent); // o no establecer ninguna imagen
            } else {
                // Establecer la imagen para las otras celdas
                QLabel *label = new QLabel();
                QPixmap pixmap("../Imagenes/Obstaculo.png"); // Cargar la imagen como QPixmap
                label->setPixmap(pixmap.scaled(30, 30, Qt::KeepAspectRatio, Qt::SmoothTransformation)); // Escalar la imagen
                label->setFixedSize(23, 23); // Asegúrate de que el QLabel tenga el mismo tamaño que la celda
                label->setAlignment(Qt::AlignCenter); // Centrar la imagen dentro del QLabel

                // Eliminar cualquier borde
                label->setStyleSheet("border: none; background-color: transparent;");

                // Colocar el QLabel en la celda
                ui->Tablero->setCellWidget(row, column, label);
            }

        }
    }
}

void Window::generateRandomObstacles() {
    // Generar obstáculos solo en la mitad izquierda del tablero (columnas 0 a 19)
    for (int row = 1; row < 20; ++row) {
        for (int column = 1; column < 19; ++column) {
            // Evitar las celdas especificadas
            if ((row == 7 && (column == 7 || column == 12)) ||
                (row == 12 && (column == 7 || column == 12))) {
                continue; // Saltar estas celdas
                }

            // Decidir aleatoriamente si colocar un obstáculo
            if (QRandomGenerator::global()->bounded(5) == 1) { // 20% de probabilidad
                // Colocar obstáculo en la celda actual
                QLabel *label = new QLabel();
                QPixmap pixmap("../Imagenes/Obstaculo.png");
                label->setPixmap(pixmap.scaled(30, 30, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                label->setFixedSize(23, 23);
                label->setAlignment(Qt::AlignCenter);
                label->setStyleSheet("border: none; background-color: transparent;");
                ui->Tablero->setCellWidget(row, column, label);

                // Colocar el obstáculo en la celda reflejada (espejo)
                QLabel *mirrorLabel = new QLabel();
                mirrorLabel->setPixmap(pixmap.scaled(30, 30, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                mirrorLabel->setFixedSize(23, 23);
                mirrorLabel->setAlignment(Qt::AlignCenter);
                mirrorLabel->setStyleSheet("border: none; background-color: transparent;");
                ui->Tablero->setCellWidget(row, 39 - column, mirrorLabel); // Columna espejo
            }
        }
    }
}